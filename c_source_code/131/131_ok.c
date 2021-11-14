/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int g_cnt;
char ***ans;
int **col;

int isRight(char *s, int st, int num, int len, int rem[len][len]) {
    int p1 = st;
    int p2 = st + num - 1;
    while (p1 < p2) {
        if (s[p1++] != s[p2--]) {
            return 0;
        }
    }
    rem[p1][p2] = 1;
    return rem[p1][p2];
}

void dfs(char *s, int st, int len, int rem[len][len], int tIdx, int tmp[len][2]) {
    int i, j, tLen;
    if (st == len) {
        ans[g_cnt] = (char **)malloc(sizeof(char *) * tIdx);
        (*col)[g_cnt] = tIdx;
        for (i = 0; i < tIdx; i++) {
            tLen = tmp[i][1] - tmp[i][0] + 1;
            ans[g_cnt][i] = (char *)malloc(sizeof(char) * (tLen + 1));
            for (j = 0; j < tLen; j++) {
                ans[g_cnt][i][j] = s[j + tmp[i][0]];
            }
            ans[g_cnt][i][tLen] = '\0';
        }
        g_cnt++;
    }

    for (int num = 1; num <= len - st; num++) {
        if (rem[st][st + num - 1] || isRight(s, st, num, len, rem)) {
            tmp[tIdx][0] = st;
            tmp[tIdx][1] = st + num - 1;
            dfs(s, st + num, len, rem, tIdx + 1, tmp);
        }
    }
}
char *** partition(char * s, int* returnSize, int **returnColumnSizes){
    int len = strlen(s);

    int rem[len][len];
    memset(rem, 0, sizeof(rem));
    int tmp[len][2];

    g_cnt = 0;
    ans = (char ***)malloc(sizeof(char **) * 32800);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 32800);
    col = returnColumnSizes;

    for (int num = 1; num <= len; num++) {
        if (rem[0][0 + num - 1] || isRight(s, 0, num, len, rem)) {
            tmp[0][0] = 0;
            tmp[0][1] = num - 1;
            dfs(s, num, len, rem, 1, tmp);
        }
    }

    returnColumnSizes = col;
    *returnSize = g_cnt;
    return ans;
}


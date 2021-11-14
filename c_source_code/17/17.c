char* mp[] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void dfs(char** res, char* digits, int* returnSize, int strLen, int idx, char* stackStr)
{
    if (idx == strLen) {
        res[*returnSize] = malloc(strLen + 1);
        strcpy(res[(*returnSize)++], stackStr);
        return;
    }
    char* tmpStr = mp[digits[idx] - '2'];
    int sLen = strlen(tmpStr);
    for (int i = 0; i < sLen; i++) {
        stackStr[idx] = tmpStr[i];
        dfs(res, digits, returnSize, strLen, idx+1, stackStr);
    }
}

char** letterCombinations(char* digits, int* returnSize)
{        
    int strLen = strlen(digits);
    if (strLen == 0) {
        return NULL;
    }

    char** res = malloc(sizeof(char*) * MAX_NUM);
    memset(res, 0x0, sizeof(char*) * MAX_NUM);

    char stackStr[5] = { 0 };
    *returnSize = 0;
    dfs(res, digits, returnSize, strLen, idx, stackStr);
    return res;
}

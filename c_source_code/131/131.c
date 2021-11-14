#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 16
char*** res;
char** vec;
int k = 0;
int j = 0;
#define true 1
#define false 0

int isCircleStr(char *str)
{
    int left = 0;
    int right = strlen(str) -1;
    while (left < right) {
        if (str[left--] != str[right++]) {
            return false;
        }
    }
    return true;
}

void dfs(char* s, int* ret, int idx)
{
    int strLen = strlen(s);
    if (idx >= strLen) {
        ret[k] = j;
        res[k++] = vec;
        return ;
    }

    for (int i = idx; i < strLen; i++) {
        char* tmpStr = malloc(sizeof(char*) * MAX_LEN);
        memcpy(tmpStr, &s[idx], i - idx + 1);
        if (isCircleStr(tmpStr)) {
            vec[j++] = tmpStr;

        } else {
            continue;
        }
        dfs(s, ret, i + 1);
        j--;
    }
}

char *** partition(char * s, int* returnSize, int** returnColumnSizes){
    res = malloc(sizeof(char**) * MAX_LEN);
    vec = malloc(sizeof(char*) * MAX_LEN);
    int* ret = malloc(sizeof(int) * MAX_LEN);
    dfs(s, ret, 0);
    *returnSize = k;
    *returnColumnSizes = ret;

    return res;
}

void test01()
{
    char str[] = "aab";
    int row = 0;
    int** col;
    char*** res = partition(str, &row, col);
    for (int i 

    return ;

}

int main()
{
    test01();

    return 0;
}

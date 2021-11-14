struct HashTable {
    char* key;
    int idx;
    UT_hash_handle hh;
};

int cmp(const void* a, const void* b)
{
    return *(char*)a > *(char*)b;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    char*** res = malloc(sizeof(char**) * strsSize);
    int* retCol = malloc(sizeof(int) * strsSize);

    struct HashTable *head, *tmp;
    head = tmp = NULL;

    int len = 0;
    for (int i = 0; i < strsSize; i++) {
        int strLen = strlen(strs[i]);
        char* tmpStr = malloc(strLen+1);
        strcpy(tmpStr, strs[i]);
        qsort(tmpStr, strLen, sizeof(char), cmp);
        HASH_FIND_STR(head, tmpStr, tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(struct HashTable));
            tmp->key = tmpStr;
            tmp->idx = len;
            HASH_ADD_KEYPTR(hh, head, tmp->key, strLen, tmp);
            res[len] = malloc(sizeof(char*) * strsSize);
            res[len][0] = strs[i];
            retCol[len++] = 1;
        } else {
            res[tmp->idx][retCol[tmp->idx]] = strs[i];
            retCol[tmp->idx]++;
        }
    }
    *returnSize = len;
    *returnColumnSizes = retCol;

    return res;
}

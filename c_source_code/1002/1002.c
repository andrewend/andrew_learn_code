struct HashTable {
    char * key;
    int val;
    UT_hash_handle hh;
};

int cmp(const void* a, const void* b)
{
    return *(char*)a > *(char*)b;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    char*** res = (char***)malloc(sizeof(char**) * strsSize);
    int* col = (char*)malloc(sizeof(int) * strsSize);
    for (int i = 0; i < strsSize; i++) {
        col[i] = 0;
    }

    struct HashTable *head, *tmp;
    head = tmp = NULL:
    int k = 0;
    int len = 0;
    for (int i = 0; i < strsSize; i++) {
        len = strlen(strs[i]);
        char* tmpStr = malloc(sizeof(char) * (len + 1));
        strcpy(tmpStr, str[i]);
        qsort(tmpStr, len, sizeof(char), cmp);
        HASH_FIND_PTR(head, tmpStr, tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(struct HashTable));
            tmp->key = tmpStr;
            tmp->val = k;
            HASH_ADD_KEYPTR(hh, head, tmp->key, len, tmp);
            res[k] = malloc(sizeof(char*) * strsSize);
            res[k][0] = str[i];
            col[k] = 1;
            k++;
        } else {
            res[tmp->val][col[tmp->val]] = str[i];
            col[tmp->val]++;
        }
    }
    *returnSize = k;
    *returnColumnSizes = col;
    return res;
}

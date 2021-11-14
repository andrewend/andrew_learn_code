struct HashTable {
    char* key;
    int val;
    UT_hash_handle hh;
};

int cmp(const void* a, const void* b)
{
    return *(char*)a > *(char*)b;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    char*** res = (char***)malloc(sizeof(char**) * strsSize);
    int * retCol = (int*)malloc(sizeof(int) * strsSize);
    for (int i = 0; i < strsSize; i++) {
        retCol[i] = 0;
    }
    struct HashTable *hashtable, *tmp;
    hashtable = tmp = NULL;

    int k = 0;
    int len = 0;
    for (int i = 0; i < strsSize; i++) {
        len = strlen(strs[i]);
        char* strTmp = malloc(sizeof(char) * (len+1));
        strcpy(strTmp, strs[i]);
        qsort(strTmp, strlen(strTmp), sizeof(char), cmp);
        HASH_FIND_STR(hashtable, strTmp, tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof *tmp);
            tmp->key = strTmp;
            tmp->val = k;
            HASH_ADD_KEYPTR(hh, hashtable, strTmp, len, tmp);
            res[k] = (char**)malloc(sizeof(char*) * strsSize);
            res[k][0] = strs[i];
            retCol[k] = 1;
            k++;
        } else {
            res[tmp->val][retCol[tmp->val]] = strs[i]; 
            retCol[tmp->val]++;
        }
    }

    *returnSize = k ;
    *returnColumnSizes = retCol;

    return res;
}

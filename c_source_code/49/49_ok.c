struct HashTable
{
    char *key;
    int val;
    UT_hash_handle hh;
};

int cmp(char*a,char*b)
{
    return *a-*b;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    struct HashTable *cnt = NULL,*tmp;
    char***ret = malloc(sizeof(char**)*strsSize);
    int *retCol = malloc(sizeof(int)*strsSize);
    //不能用memset(retCol,0,sizeof(retCol))，小心内存泄露！
    for(int i = 0;i < strsSize;i++)
    {
        retCol[i] = 0;
    }
    int size = 0;
    for(int i = 0;i < strsSize;i++)
    {
        int len = strlen(strs[i]);
        char* tmpStr = malloc(sizeof(char)*(len+1));
        strcpy(tmpStr,strs[i]);
        qsort(tmpStr,len,sizeof(char),cmp);
        HASH_FIND_STR(cnt,tmpStr,tmp);
        if(tmp==NULL)
        {
            tmp = malloc(sizeof *tmp);
            tmp->key = tmpStr;
            tmp->val = size;
            HASH_ADD_KEYPTR(hh,cnt,tmp->key,len,tmp);
            ret[size] = malloc(sizeof(char*)*strsSize);
            ret[size][0] = strs[i];
            retCol[size++] = 1;
        }
        else
        {
            ret[tmp->val][retCol[tmp->val]] = strs[i];
            retCol[tmp->val]++;
        }
    }
    *returnSize = size;
    *returnColumnSizes = retCol;
    return ret;
}

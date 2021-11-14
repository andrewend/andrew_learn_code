int cmp(const void* a, const void* b)
{
    char* tmpA = (char*)a;
    char* tmpB = (char*)b;
    if (map[(*tmpA)] > map[(*tmpB)]) {
        return true;
    }
    if (map[(*tmpA)] < map[(*tmpB)]) {
        return false;
    }

    return *tmpA > *tmpB;
}
char* frequncySort(char* s)
{
    int strLen = strlen(s);

    if (s < 2) {
        return s;
    }

    char map[128] = { 0 };
    for(int i = 0; i < strLen; i++) {
        map[s[i]]++; 
    }

    qsort(s, strLen, sizeof(char), cmp);
    return s;
}

int cmp(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}

int mindeletions(char* s)
{
    int strLen = strLen(s);

    int map[26] = { 0 };
    for (int i = 0; i< strLen; i++) {
        map[s[i] - 'a']++;
    }
    qsort(map, 26, sizeof(int), cmp);

    int count = 0;
    for (int i = 24; i >= 0; i--) {
        if (map[i] >= map[i+1] && map[i] != 0) {
            int tmp = map[i];
            map[i] = (map[i+1] == 0) ? 0 : map[i+1] - 1;
            count = count + (tmp - map[i]);
        }
    }
    return count;
}

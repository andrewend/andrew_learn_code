int cmp(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}

int minDeletions(char* s)
{
    int strLen = strlen(s);
    int map[26] = { 0 };

    for (int i = 0; i < strLen; i++) {
        map[s[i] - 'a']++;
    }
    qsort(map, 26, sizeof(int), cmp);

    int tmp = 0;
    int count = 0;
    for (int i = 24; i >= 0; i--) {
        if (map[i] != 0 && map[i] >= map[i+1]) {
            tmp = map[i];
            map[i] = (map[i+1] == 0) ? 0 : (map[i+1] - 1);
            count += (tmp - map[i]);
        }
    }
    return count;
}

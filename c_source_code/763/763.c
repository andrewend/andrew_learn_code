int* partitionLabels(char * s, int* returnSize){
    int strLen = strlen(s);
    int map[26] = { 0 };

    for (int i = 0; i < strLen; i++) {
        map[s[i] - 'a'] = i;
    }
    int start = 0;
    int end = 0;
    int* res = malloc(sizeof(int) * (strLen + 1));
    int size = 0;

    for (int i = 0; i < strLen; i++) {
        end = fmax(map[s[i] - 'a'], end);
        if (i == end) {
            res[size++] = end - start + 1;
            start = end + 1;
        }
    }
    *returnSize = size;
    return res;
}

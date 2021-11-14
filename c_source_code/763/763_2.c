int* partitionLabels(char * s, int* returnSize){
    int strLen = strlen(s);
    int left = 0;
    int right = 0;
    int map[26] = { 0 };
    for (int i = 0; i < strLen; i++) {
        map[s[i] - 'a'] = i;
    }

    int* res = malloc(sizeof(int) * strLen);
    int size = 0;
    int start = 0;
    int end = 0;
    for (int i = 0; i < strLen; i++) {
        end = fmax(end, map[s[i] - 'a']);
        if (end == i) {
            res[size++] = end - start + 1;
            start = end + 1;
        }
    }


    *returnSize = size;
    return res;
}

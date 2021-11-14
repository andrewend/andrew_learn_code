int characterReplacement(char* s, int k){
    int strLen = strlen(s);
    int left = 0;
    int right = 0;
    int map[26] = { 0 };

    int max = 0;
    while (right < strLen) {
        map[s[right] - 'A']++;
        max = fmax(max, map[s[right] - 'A']);
        if (right - left + 1 - max > k) {
            map[s[left++] - 'A']--;
        }

        right++;
    }

    return (right - 1) - left + 1;
}

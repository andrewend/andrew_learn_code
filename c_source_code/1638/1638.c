int countSubstrings(char * s, char * t){
    if (s == NULL || t == NULL || strlen(s) == 0 || strlen(t) == 0) {
        return 0;
    }

    int count = 0;
    for (int i = 0; i < strlen(s); i++) {
        for (int j = 0; j < strlen(t); j++) {
            int diff = 0;
            for (int k = 0; k + i < strlen(s) && k + j < strlen(t); k++) {
                if (s[k + i] != s[k + j]) {
                    diff++;
                }
                if (diff == 1) {
                    count++;
                }
                if (diff > 1) {
                    break;
                }
            }
        }
    }
    return count;
}

char * getSmallestString(int n, int k){
    int remain = k;
    char* res = (char*)malloc(sizeof(char) * (n + 1));

    memset(res, 'a', n);
    remain -= n;

    for (int i = n -1; i >= 0; i--) {
        int d = remain > 25 ? 25 : remain;
        res[i] += d;
        remain -= d;
        if (remain == 0) {
            break;
        }
    }
    res[n] = '\0';
    return res;
}

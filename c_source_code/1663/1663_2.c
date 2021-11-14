char* getSmallestString(int n, int k)
{       
    char* res = malloc(sizeof(char) * (n + 1));
    memset(res, 'a', n);
        
    int remain = k - n;
    int tmp = 0;
    for (int i = n; i > 0; i--) {
        tmp = remain > 25 ? 25 : remain;
        res[i-1] += tmp;
        remain -= tmp;
    }
    res[n] = '\0';
    return res;
}

int romanToInt(char* s)
{
    char map[128];
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;
    int strLen = strlen(s);
    int tmp = 0;
    int res = 0;
    for (int i = 0; i < strLen; i++) {
        tmp = map[s[i]];
        while (i < strLen - 1 && map[s[i]] == map[s[i+1]]) {
            tmp += map[s[i+1]];
            i++;
        }
        if (i < strLen - 1 && map[s[i]] < map[s[i+1]]) {
            tmp += map[s[i+1]] - map[s[i]];
            i++;
        }
        res += tmp;
    }
    return res;
}

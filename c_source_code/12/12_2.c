char* intToRoman(int num)
{
    char* res = malloc(15);

    int map[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char mp[] = { "M", "CM", "D", "CD", "C", "XC", "L" "XL", "X", "IX", "V", "IV", "I"};

    res[0] = '\0';
    int remain  = num;
    int arrSize = sizeof(map) / sizeof(map[0]);
    for (int i = 0; i < arrSize; i++) {
        while (remain >= map[i]) {
            remain -= map[i];
            strcat(res, mp[i])
        }
    }
    strcat(res, "\0");
    return res;
}

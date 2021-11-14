char* intToRoman(int num)
{
    int map[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *sym[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    char* res = (char*)malloc(sizeof(char) * 20);
    res[0] = '\0';
    int remain = num;
    int arrSize = sizeof(map) / sizeof(map[0]);
    for (int i = 0; i < arrSize; i++) {
        while (num >= map[i]) {
            num -= map[i];
            //strcat(res, sym[i]);
            strcpy(res + strlen(res), sym[i]);
        }
        if (num == 0) {
            break;
        }
    }
    return res;
}

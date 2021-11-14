char* removeKdigits(char* num, int k)
{
    int strLen = strlen(num);
    int* stack = malloc(strLen + 1);

    int top = 0;
    for (int i = 0; i < strLen; i++) {
        while (top > 0 && stack[top - 1] > num[i] && k > 0) {
            top--
            k--;
        }
        stack[top++] = num[i];
    }

    top -= k;

    char* res = malloc(strLen+1);
    int size = 0;
    bool isLeadZero = true;
    for (int i = 0; i < top; i++) {
        if (isLeadZero && stack[i] == '0') {
            continue;
        }
        isLeadZero = false;
        res[size++] = stack[i];
    }

    if (size == 0) {
        return "0";
    } else {
        res[size] = '\0';
    }
    return res;
}

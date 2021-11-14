int calculate(char * s){                                                                                                           
    int strLen = strlen(s);
    long num = 0;

    int* stack = malloc(sizeof(int)*(strLen+1));
    memset(stack, 0x0, strLen+1);
    int top = 0;
    char op = '+';
    char ch; 
    for (int i = 0; i < strLen; i++) 
    {   
        ch = s[i];
        if (isdigit(ch)) {
            num = num * 10 + (int)(ch - '0');
        }

        if (!isdigit(s[i]) && ch != ' ' || i == strLen - 1) {
            switch (op) {
                case '+':
                    stack[top++] = num;
                    break;
                case '-':
                    stack[top++]= -num;
                    break;
                case '*':
                    stack[top-1] *= num;
                    break;
                default:
                    stack[top-1] /= num;
                    break;
            }
            op = ch; 
            num = 0;
        }
    }
    long res = 0;
    for (int i = 0; i < top; i++) {
        res += stack[i];
    }
    return res;
}

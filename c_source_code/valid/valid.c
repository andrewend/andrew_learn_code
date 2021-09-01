#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int stack[10000] = { 0 };
int pop = 0;

char getPair(char ch) {
    switch (ch) {
        case ']':
            return '[';
        case '}':
            return '{';
        case ')':
            return '(';
        default:
            printf("Invalide char %c\n", ch);
    }
}

bool isValid(char *s) {
    unsigned int StrLen = strlen(s);
    for (int i = 0; i < StrLen; i++) {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
            stack[pop++] = s[i];
        } else {
            //printf("s[i] %c\n", s[i]);
            if (stack[--pop] == getPair(s[i])) {
                //printf("=\n");
                ;  // nothing
            } else {
                
                //printf("isvalid:false: %c\n", stack[pop]);
                return false;
            }
        }
    }
    return true;

}

int main()
{
    char s[] = "()";
    printf("%d\n", isValid(s));
    char s1[] = "()[]{}";
    printf("%d\n", isValid(s1));
    char s2[] = "(]";
    printf("%d\n", isValid(s2));
    char s3[] = "([)]";
    printf("%d\n", isValid(s3));
    char s4[] = "{[]}";
    printf("%d\n", isValid(s4));


    return 0;
}

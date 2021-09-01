#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

int lengthOfLastWord_bak(char * s){
    char* p = s;
    while (*p != '\0') {
        p++;
    }

    while (!isalpha(*p) && p != s) {
        p--;
    }

    if (p == s) {
        return !isalpha(*s) == 0 ? 1 : 0;
    }

    char* end = p;
    while (isalpha(*p) && p != s) {
        p--;
    }
    char* start = p;
    if (*start == ' ');
        return end - start;

    if (start == s) {
        return end - start + 1;
    }

    return end - start;
}

int lengthOfLastWord(char * s){
    char* p = s;
    int i = strlen(s) - 1;

    while (i >=0 && p[i] == ' ') {
        i--;
    }

    int count = 0;
    while (i >= 0 && p[i] != ' ') {
        count++;
        i--;
    }
    return count;
}

void test1()
{
    char input[] = "Hello World";
    int res = lengthOfLastWord(input);
    printf("res: %d\n", res);
    assert(res == 5);
}

void test2()
{
    char input[] = " ";
    int res = lengthOfLastWord(input);
    printf("res: %d\n", res);
    assert(res == 0);
}
void test3()
{
    char input[] = "a";
    int res = lengthOfLastWord(input);
    printf("res: %d\n", res);
    assert(res == 1);
}

void test4()
{
    char input[] = "a ";
    int res = lengthOfLastWord(input);
    printf("res: %d\n", res);
    assert(res == 1);
}

void test5()
{
    char input[] = " a";
    int res = lengthOfLastWord(input);
    printf("res: %d\n", res);
    assert(res == 1);
}

int main()
{
#if 1
    test1();
    test2();
    test3();
    test4();
#endif
    test5();

    return 0;
}

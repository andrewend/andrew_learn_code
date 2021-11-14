#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <limits.h>
#define printf(...)

#if 1
int myAtoi(char * s)
{
    char* p = s;
    while (*p == ' ') {
        *p++;
    }

    int sign = 1;
    if (*p == '-') {
        sign = -1;
        p++;
    } else if (*p == '+') {
        p++;
    }
    long long res = 0;
    while (isdigit(*p)) {
        res = res * 10 + *p - '0';
        if (res > INT_MAX) {
            break;
        }
        printf("-res:%lld\n", res);
        p++;
    }
    if (sign > 0) {
        return (res > INT_MAX) ? INT_MAX : res;
    }
    if (res > (long long)INT_MAX) {
        printf("-res:%lld, %d, %d\n", res, INT_MIN, INT_MAX);
        printf("MIN\n");
        return INT_MIN;
    } else {
        return res * sign;
    }

    return res * sign;
}
#endif

void test01()
{
    char inputStr[] = "42";
    int res = myAtoi(inputStr);
    printf("res:%d\n", res);
    int expectRes = atoi(inputStr);
    assert(res == expectRes);
}
void test02()
{
    char inputStr[] = "   -42";
    int res = myAtoi(inputStr);
    printf("res:%d\n", res);
    int expectRes = atoi(inputStr);
    assert(res == expectRes);
}
#if 1
void test03()
{
    char inputStr[] = "4193 with words";
    int res = myAtoi(inputStr);
    printf("res:%d\n", res);
    int expectRes = atoi(inputStr);
    assert(res == expectRes);
}
void test04()
{
    char inputStr[] = "words and 987";
    int res = myAtoi(inputStr);
    printf("res:%d\n", res);
    int expectRes = atoi(inputStr);
    assert(res == expectRes);
}

void test05()
{
    char inputStr[] = "-91283472332";
    int res = myAtoi(inputStr);
    printf("res:%d\n", res);
    //int expectRes = atoi(inputStr);
    assert(res == -2147483648);
}
void test06()
{
    char inputStr[] = "-2147483647";
    int res = myAtoi(inputStr);
    printf("res:%d\n", res);
    //int expectRes = atoi(inputStr);
    assert(res == -2147483647);
}

void test07()
{
    char inputStr[] = "-2147483649";
    int res = myAtoi(inputStr);
    printf("res:%d\n", res);
    //int expectRes = atoi(inputStr);
    assert(res == -2147483648);
}

void test08()
{
    char inputStr[] = "20000000000000000000";
    int res = myAtoi(inputStr);
    printf("res:%d\n", res);
    //int expectRes = atoi(inputStr);
    assert(res == 2147483647);
}
#endif
int main()
{
#if 1
    test01();
    test02();
    test03();
    test04();
    test05();
#endif
    test06();
    test07();
    test08();

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define printf(...)

void swap(char* left, char* right)
{
    char ch = *left;
    *left = *right;
    *right = ch;
}

void reverse(char * res)
{
    int left = 0;
    int right = strlen(res) - 1;
    while (left < right) {
        swap(&res[left++], & res[right--]);
    }
}

char* convertToTitle(int columnNumber)
{
    printf("%s\n", __func__);
    char* res = (char*)malloc(40);
    int remain = columnNumber;
    int k = 0;
    while (remain > 0) {
        printf("k:%d\t\n", k);
        if ((k + 1) % 10 == 0) {
            printf("\n");
        }
        printf("div:%d\n", (remain - 1) % 26);
        res[k++] = 'A' + (remain - 1) % 26;
        remain = (remain - 1) / 26;
        printf("remain:%d\n", remain);
    }
    res[k++] = '\0';
    printf("res:%s\n", res);

    reverse(res);
    return res;
}

void test01()
{
    int columnNumber = 1;
    char* res = convertToTitle(columnNumber);
    char resExect[] = "A";
    assert(strcmp(res, resExect) == 0);
    free(res);
}

void test02()
{
    int columnNumber = 28;
    char* res = convertToTitle(columnNumber);
    char resExect[] = "AB";
    assert(strcmp(res, resExect) == 0);
    free(res);
}
void test03()
{
    int columnNumber = 701;
    char* res = convertToTitle(columnNumber);
    char resExect[] = "ZY";
    assert(strcmp(res, resExect) == 0);
    free(res);
}
void test04()
{
    int columnNumber = 2147483647;
    char* res = convertToTitle(columnNumber);
    char resExect[] = "FXSHRXW";
    assert(strcmp(res, resExect) == 0);
    free(res);
}
void test05()
{
    int columnNumber = 1;
    char* res = convertToTitle(columnNumber);
    char resExect[] = "A";
    assert(strcmp(res, resExect) == 0);
    free(res);
}

void test06()
{
    int columnNumber = 1;
    char* res = convertToTitle(columnNumber);
    char resExect[] = "A";
    assert(strcmp(res, resExect) == 0);
    free(res);
}
void test07()
{
    int columnNumber = 1;
    char* res = convertToTitle(columnNumber);
    char resExect[] = "A";
    assert(strcmp(res, resExect) == 0);
    free(res);
}

int main()
{
#if 1
    test01();
    test02();
#endif
    test03();
#if 1
    test04();
    test05();
    test06();
    test07();
#endif

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

// #define DEBUG
#ifndef DEBUG
    #define printf(...)
#else
    /* nothing */
#endif

void swap(const void* a, const void* b)
{
    char tmp = *(char *)a;
    *(char*)a = *(char*)b;
    *(char*)b = tmp;
}

void reverse(char* res)
{
    int left = 0;
    int right = strlen(res)- 1;
    while (left < right) {
        swap(&res[left++], &res[right--]);
    }
}

char* licenseKeyFormatting(char* s, int k)
{
    int strLen = strlen(s);
    int len = (strLen / k + 1 ) * k * 2;
    char* result = (char*)malloc(len + 1);
    char* res = result;
    int i = strLen - 1, j = 0, l =0;
    while (i >= 0) {
        if (s[i] == '-') {
            i--;
            continue;
        }
        if (islower(s[i])) {
            res[l++] = s[i] - 'a' + 'A';
            printf("lower:s[%d]:%c\n", i, s[i]);
        } else {
            res[l++] = s[i];
            printf("s[%d]:%c\n", i, s[i]);
        }
        j++;
        if (j >= k) {
            printf("j:%d------------\n", j);
            j = 0;
            res[l++] = '-';
        }
        i--;
    }

    if (l > 0 && res[l-1] == '-') {
        res[l-1] = '\0';
    } else {
        res[l] = '\0';
    }

    printf("res:%s\n", result);
    reverse(result);
    printf("res:%s\n", result);
    return result;
}

void test01()
{
    char inputStr[] = "5F3Z-2e-9-w";
    int k = 4;
    char* res = licenseKeyFormatting(inputStr, k);
    char expectStr[] = "5F3Z-2E9W";
    printf("res:%s\n", res);
    assert(strcmp(res, expectStr) == 0);
    free(res);
}

void test02()
{
    char inputStr[] = "2-5g-3-J";
    int k = 2;
    char* res = licenseKeyFormatting(inputStr, k);
    printf("res:%s\n", res);
    char expectStr[] = "2-5G-3J";
    assert(strcmp(res, expectStr) == 0);
    free(res);
}

void test03()
{
    char inputStr[] = "aaaa";
    int k = 2;
    char* res = licenseKeyFormatting(inputStr, k);
    printf("res:%s\n", res);
    char expectStr[] = "AA-AA";
    assert(strcmp(res, expectStr) == 0);
    free(res);
}

void test04()
{
    char inputStr[] = "0123456789";
    int k = 1;
    char* res = licenseKeyFormatting(inputStr, k);
    printf("res:%s\n", res);
    char expectStr[] = "0-1-2-3-4-5-6-7-8-9";
    assert(strcmp(res, expectStr) == 0);
    free(res);
}

void test05()
{
    char inputStr[] = "----";
    int k = 3;
    char* res = licenseKeyFormatting(inputStr, k);
    printf("res:%s\n", res);
    char expectStr[] = "";
    assert(strcmp(res, expectStr) == 0);
    free(res);
}

int main()
{
#if 1
    test01();
    test02();
    test03();
    test04();
#endif
    test05();

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define printf(...)  

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int* dig = (int*)malloc(sizeof(int) * digitsSize);
    memcpy(dig, digits, digitsSize * sizeof(int));

    int* res;
    int cy = 1;
    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = dig[i] + cy;
        dig[i] = sum % 10;
        cy = (sum + cy) / 10;
    }
    *returnSize = digitsSize + cy;
    if (cy == 1) {
        res = (int *)malloc(sizeof(int) * (digitsSize + 1));
        res[0] = cy ;
        memcpy(res+1, dig, digitsSize * sizeof(int));
    } else {
        res = (int *)malloc(sizeof(int) * (digitsSize + 1));
        memcpy(res, dig, digitsSize * sizeof(int));
    }

    return res;
};

void test01()
{
    int test[] = { 1, 2, 3};
    int arrySize = sizeof(test) / sizeof(test[0]);
    int retSize = 0;
    int* res = plusOne(test, arrySize, &retSize);
    assert(retSize == arrySize);
    for (int i = 0; i < retSize; i++) {
        printf("ret[i] = %d\n", res[i]);
    }
    int resExpect[] = { 1, 2, 4 };
    assert(memcmp(res, resExpect, retSize) == 0);
}

void test02()
{
    int test[] = { 4, 3, 2, 1};
    int arrySize = sizeof(test) / sizeof(test[0]);
    int retSize = 0;
    int* res = plusOne(test, arrySize, &retSize);
    assert(retSize == arrySize);
    for (int i = 0; i < retSize; i++) {
        printf("ret[i] = %d\n", res[i]);
    }
    int resExpect[] = { 4, 3, 2 ,2};
    assert(memcmp(res, resExpect, retSize) == 0);
}

void test03()
{
    int test[] = { 0 };
    int arrySize = sizeof(test) / sizeof(test[0]);
    int retSize = 0;
    int* res = plusOne(test, arrySize, &retSize);
    assert(retSize == arrySize);
    for (int i = 0; i < retSize; i++) {
        printf("ret[i] = %d\n", res[i]);
    }
    int resExpect[] = { 1 };
    assert(memcmp(res, resExpect, retSize) == 0);
}

void test04()
{
    int test[] = { 9, 9, 9, 9 };
    int arrySize = sizeof(test) / sizeof(test[0]);
    int retSize = 0;
    int* res = plusOne(test, arrySize, &retSize);
    printf("retSize = %d\n", retSize);
    assert(retSize == (arrySize +1));
    for (int i = 0; i < retSize; i++) {
        printf("ret[i] = %d\n", res[i]);
    }
    int resExpect[] = { 1,0, 0, 0, 0 };
    assert(memcmp(res, resExpect, retSize) == 0);
}

int main()
{
    test01();
    test02();
    test03();
    test04();
    return 0;
}

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int* twoSum(int* numbers, int numbersSisze, int target, int* returnSize)
{
    *returnSize = 2;
    int* res = (int*)malloc(sizeof(int) * (*returnSize));
    int remain;
    for (int i = 0; i < numbersSisze; i++) {
        remain = target - numbers[i];
        int* tmp = bsearch(&remain, numbers + i + 1, numbersSisze - i - 1, sizeof(int), cmp);
        if (tmp == NULL) {
            continue;
        }
        res[0] = i + 1;
        res[1] = (tmp - numbers) + 1;
        return res;
    }
    return res;
}

void print(int nums[], int numsSize)
{
    printf("%s, %d\n", __func__, __LINE__);
    for (int i = 0; i < numsSize; i++) {
        printf("%d\t", nums[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void test01()
{
    int numbers[] = { 2, 7, 11, 15 };
    int numbersSisze = sizeof(numbers) / sizeof(numbers[0]);
    int target = 9;
    int returnSize;
    int* res = twoSum(numbers, numbersSisze, target, &returnSize);
    print(res, returnSize);
    int expectRes[] = { 1, 2 };
    assert(memcmp(expectRes, res, returnSize) == 0);
}

void test02()
{
    int numbers[] = { 2, 3, 4 };
    int numbersSisze = sizeof(numbers) / sizeof(numbers[0]);
    int target = 6;
    int returnSize;
    int* res = twoSum(numbers, numbersSisze, target, &returnSize);
    print(res, returnSize);
    int expectRes[] = { 1, 3 };
    assert(memcmp(expectRes, res, returnSize) == 0);
}

void test03()
{
    int numbers[] = { -1, 0 };
    int numbersSisze = sizeof(numbers) / sizeof(numbers[0]);
    int target = -1;
    int returnSize;
    int* res = twoSum(numbers, numbersSisze, target, &returnSize);
    print(res, returnSize);
    int expectRes[] = { 1, 2 };
    assert(memcmp(expectRes, res, returnSize) == 0);
}
int main()
{
    test01();
    test02();
    test03();

    return 0;
}

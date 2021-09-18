#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
    for (int i = 0; i < numsSize; i++) {
        nums[i] = nums[i] * nums[i];
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    *returnSize = numsSize;
    return nums;
}

void test01()
{
    int nums[] = { -4, -1, 0, 3, 10 };
    int arrSize = sizeof(nums) / sizeof(nums[0]);
    int* res = (int*)malloc(sizeof(int) * arrSize);
    int returnSize = 0;
    int expectRes[] = { 0, 1, 9, 16, 100 };

    res = sortedSquares(nums, arrSize, &returnSize);
    assert(memcmp(res, expectRes, arrSize) == 0);
}

void test02()
{
    int nums[] = { -7, -3, 2, 3, 11 };
    int arrSize = sizeof(nums) / sizeof(nums[0]);
    int* res = (int*)malloc(sizeof(int) * arrSize);
    int returnSize = 0;
    int expectRes[] = { 4, 9, 9, 49, 121 };

    res = sortedSquares(nums, arrSize, &returnSize);
    assert(memcmp(res, expectRes, arrSize) == 0);
}
int main()
{
    test01();
    test02();
    return 0;

}

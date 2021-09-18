#include <stdio.h>
#include <assert.h>
#include <string.h>

void rotate_old(int* nums, int numsSize, int k)
{
    k = k % numsSize;
    for (int j = 0; j < k; j++) {
        int tmp = nums[numsSize - 1];
        for (int i = numsSize - 1; i > 0; i--) {
            nums[i] = nums[i - 1];
        }
        nums[0] = tmp;
    }
}

void rotate(int* nums, int numsSize, int k)
{
    int newArr[numsSize];
    for (int i = 0; i < numsSize; ++i) {
        newArr[(i + k) % numsSize] = nums[i];
    }
    for (int i = 0; i < numsSize; ++i) {
        nums[i] = newArr[i];
    }
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
    int nums[] = { 1, 2, 3, 4, 5, 6, 7 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;
    print(nums, numsSize);
    rotate(nums, numsSize, k);
    print(nums, numsSize);
    int expectNums[] = { 5, 6, 7, 1, 2, 3, 4 };
    assert(memcmp(expectNums, nums, numsSize) == 0);
}

void test02()
{
    int nums[] = { 1, 2, 3, 4, 5, 6, 7 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 100005;
    int test = k % 7;
    printf("test: %d\n", test);
    rotate(nums, numsSize, k);
    int expectNums[] = { 5, 6, 7, 1, 2, 3, 4 };
    assert(memcmp(expectNums, nums, numsSize) == 0);
}
int main()
{
    printf("---------------\n");
    test01();
    test02();

    return 0;
}

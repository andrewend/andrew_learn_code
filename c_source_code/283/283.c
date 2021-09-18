#include <stdio.h>
#include <assert.h>
#include <string.h>

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

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void moveZeroes(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            continue;
        }
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] == 0) {
                continue;
            }
            swap(&nums[i], &nums[j]);
            break;
        }
    }
}

void test01()
{
    int nums[] = { 0, 1, 0, 3, 12 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    print(nums, numsSize);
    moveZeroes(nums, numsSize);
    print(nums, numsSize);
    int expectNums[] = { 1, 3, 12, 0, 0 };
    assert(memcmp(expectNums, nums, numsSize) == 0);
}

int main()
{
    test01();
    return 0;
}

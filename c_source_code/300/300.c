//示例 1：
//
//输入：nums = [10,9,2,5,3,7,101,18]
//输出：4
//解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
//示例 2：
//
//输入：nums = [0,1,0,3,2,3]
//输出：4
//示例 3：
//
//输入：nums = [7,7,7,7,7,7,7]
//输出：1
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

void print(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++) {
        printf("nums[i]: %d\t", nums[i]);
    }
    printf("\n");
}

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int lengthOfLIS(int* nums, int numsSize)
{
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = fmax(dp[i], dp[j]+1);
            }
        }
    }
    qsort(dp, numsSize, sizeof(int), cmp);
    int res = dp[numsSize-1];
    free(dp);
    return res;
}

void test01()
{
    int nums[] = { 10,9,2,5,3,7,101,18 };
    int arraySisze = sizeof (nums) / sizeof(nums[0]);
    int res = lengthOfLIS(nums, arraySisze);
    assert(res == 4);
}

void test02()
{
    int nums[] = { 0,1,0,3,2,3 };
    int arraySisze = sizeof (nums) / sizeof(nums[0]);
    int res = lengthOfLIS(nums, arraySisze);
    assert(res == 4);
}

void test03()
{
    int nums[] = { 7,7,7,7,7,7,7 };
    int arraySisze = sizeof (nums) / sizeof(nums[0]);
    int res = lengthOfLIS(nums, arraySisze);
    assert(res == 1);
}

int main()
{
    test01();
    test02();
    test03();

    return 0;
}

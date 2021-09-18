#include<stdio.h>
#include <stdio.h>
#include <assert.h>

int search(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int mid;
    while(left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

void test01()
{
    int nums[] = { -1, 0, 3, 5, 9, 12 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 2;
    int res = search(nums, numsSize, target);
    assert(res == -1);
}

void test02()
{
    int nums[] = { -1, 0, 3, 5, 9, 12 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;
    int res = search(nums, numsSize, target);
    assert(res == 4);
}

int main()
{
    test01();
    test02();

    return 0;
}

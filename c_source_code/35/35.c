#include <stdio.h>
#include <assert.h>

int searchInsert(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (target == nums[mid]) {
            return mid;
        }
        if (target > nums[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (target == nums[left]) {
        return left;
    }
    
    if (target > nums[left]) {
        return left +1;
    }
    return left;
}

void test01()
{
    int nums[] = { 1, 3, 5, 6 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 5;
    int res = searchInsert(nums, numsSize, target);
    assert(res == 2);
}

void test02()
{
    int nums[] = { 1, 3, 5, 6 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 2;
    int res = searchInsert(nums, numsSize, target);
    assert(res == 1);
}
void test03()
{
    int nums[] = { 1, 3, 5, 6 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 7;
    int res = searchInsert(nums, numsSize, target);
    printf("res: %d\n", res);
    assert(res == 4);
}
void test04()
{
    int nums[] = { 1, 3, 5, 6 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 0;
    int res = searchInsert(nums, numsSize, target);
    printf("res: %d\n", res);
    assert(res == 0);
}

void test05()
{
    int nums[] = { 1 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 0;
    int res = searchInsert(nums, numsSize, target);
    printf("res: %d\n", res);
    assert(res == 0);
}
int main()
{
    test01();
    test02();
    test03();
    test04();
    test05();
    return 0;
}

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int left, right;
    left = 0;
    right = numbersSize - 1;
    int remain;
    *returnSize = 2;
    int *res = (int*)malloc(sizeof(int) * numbersSize);
    for (int i = 0; i < numbersSize; i++) {
        remain = target - numbers[i];
        int* pos = bsearch(&remain, numbers + i + 1, numbersSize - i - 1, sizeof(int), cmp);
		if (pos == NULL) {
			continue;
		}
        res[0] = i + 1;
        res[1] = pos - numbers + 1;
        return res;
    }
    return NULL;
}

void test01()
{
	int nums[] = { 5, 25, 75};
	int numsArray = sizeof(nums) / sizeof(nums[0]);
	int target = 100;
	int returnSize;
	int* res = twoSum(nums, numsArray, target, &returnSize);
	printf("res:%d, %d\n", res[0], res[1]);
}

void test02()
{
	int nums[] = { 5, 25, 75};
	int numsArray = sizeof(nums) / sizeof(nums[0]);
	int target = 30;
	int returnSize;
	int* res = twoSum(nums, numsArray, target, &returnSize);
	printf("res:%d, %d\n", res[0], res[1]);
}

void test03()
{
	int nums[] = { 1, 3, 4, 4};
	int numsArray = sizeof(nums) / sizeof(nums[0]);
	int target = 8;
	int returnSize;
	int* res = twoSum(nums, numsArray, target, &returnSize);
	printf("res:%d, %d\n", res[0], res[1]);
}
int main()
{
	test01();
	test02();
	test03();

	return 0;
}

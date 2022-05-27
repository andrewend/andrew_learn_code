#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int* res = (int*)malloc(sizeof(int) * 2);
	*returnSize = 2;

	for (int i = 0; i < numsSize; i++) {
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[i] == target - nums[j]) {
				res[0] = i;
				res[1] = j;
				return res;
			}
		}
	}
	res[0] = -1;
	res[1] = -1;
	return res;
}
struct map {
	int val;
	int idx;
};

int cmp(const void *a, const void *b)
{
	return ((struct map*)a)->val - ((struct map*)b)->val;
}

int* twoSum_2(int* nums, int numsSize, int target, int* returnSize)
{
	int* res = (int*)malloc(sizeof(int) * 2);
	*returnSize = 2;
	struct map* mp = (struct map*)malloc(sizeof(struct map) * numsSize);
	for (int i = 0; i < numsSize; i++) {
		mp[i].val = nums[i];
		mp[i].idx = i;
	}
	qsort(mp, numsSize, sizeof(struct map), cmp);

	int remain;
	for (int i = 0; i < numsSize; i++) {
		remain = target - nums[i];
		struct map* pos = bsearch(&remain, mp, numsSize, sizeof(struct map), cmp);
		if (pos != NULL) {
	 		res[0] = i;
			res[1] = mp[pos-mp].idx;
			return res;
		}
	}
	res[0] = -1;
	res[1] = -1;
	return res;
}

void test01()
{
	int nums[] = { 2, 7, 11, 9};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int target = 9;
	int returnSize;
	int* res = twoSum(nums, numsSize, target, &returnSize);
	int* expectRes = twoSum_2(nums, numsSize, target, &returnSize);
	assert(memcmp(res, expectRes, 2) == 0);
}

int main()
{
	test01();
}

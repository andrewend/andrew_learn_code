#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    *returnSize = 2;
    int* res = (int*)malloc(sizeof(int) * (*returnSize));
	int left, right;
	left = 0;
	right = numbersSize - 1;
	int sum;
	*returnSize = 2;
	while (left < right) {
		sum = numbers[left] + numbers[right];
		if (sum == target) {
			res[0] = left + 1;
			res[1] = right + 1;
			return res;
		}
		if (sum < target) {
			left++;
		} else {
			right--;
		}
	}
	res[0] = -1;
	res[1] = -1;
    return res;
}

void print(int nums[], int numsSize)
{
    //printf("%s, %d\n", __func__, __LINE__);
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

void test04()
{
    int numbers[] = { 1, 2, 4, 4 };
    int numbersSisze = sizeof(numbers) / sizeof(numbers[0]);
    int target = 8;
    int returnSize;
    int* res = twoSum(numbers, numbersSisze, target, &returnSize);
    print(res, returnSize);
    int expectRes[] = { 3, 4 };
    assert(memcmp(expectRes, res, returnSize) == 0);
}
int main()
{
    test01();
    test02();
    test03();
    test04();

    return 0;
}

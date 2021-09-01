#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

int maxFrequency(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), cmp);

#if 0
    for (int i = 0; i < numsSize; i++) {
        printf("i:%d, %d\n", i, nums[i]);
    }
#endif
    int left = 0; 
    int right = 1;
    int max = 1;
    int sum = 0;
    while (left < right && right < numsSize) {
        sum += (long long)(nums[right] - nums[right-1]) * (right - left);
        if (sum > k) {
            sum -= (nums[right] - nums[left]);
            left++;
        } else {
            right++;
        }
        max = (right - left) > max ? (right - left) : max;
        //printf("max = %d\n", max);
    }

    return max;
}

void test01()
{
    int ret = 0;
    int num[] = { 1, 2, 4};
    int k = 5;
    int arrSize = sizeof(num) / sizeof(num[0]);
    ret = maxFrequency(num, arrSize, k);
    printf("ret = %d\n", ret);
    assert(ret == 3);
}

void test02()
{
    int ret = 0;
    int num[] = { 1, 4, 8, 13};
    int k = 5;
    int arrSize = sizeof(num) / sizeof(num[0]);
    ret = maxFrequency(num, arrSize, k);
    printf("ret = %d\n", ret);
    assert(ret == 2);
}

void test03()
{
    int ret = 0;
    int num[] = { 3, 9, 6 };
    int k = 2;
    int arrSize = sizeof(num) / sizeof(num[0]);
    ret = maxFrequency(num, arrSize, k);
    printf("ret = %d\n", ret);
    assert(ret == 1);
}

void test04()
{
    int ret = 0;
    int num[] = {  6 };
    int k = 100;
    int arrSize = sizeof(num) / sizeof(num[0]);
    ret = maxFrequency(num, arrSize, k);
    printf("ret = %d\n", ret);
    assert(ret == 1);
}

void test05()
{
    int ret = 0;
    int num[] = { 9930,9923,9983,9997,9934,9952,9945,9914,9985,9982,9970,9932,9985,9902,9975,9990,9922,9990,9994,9937,9996,9964,9943,9963,9911,9925,9935,9945,9933,9916,9930,9938,10000,9916,9911,9959,9957,9907,9913,9916,9993,9930,9975,9924,9988,9923,9910,9925,9977,9981,9927,9930,9927,9925,9923,9904,9928,9928,9986,9903,9985,9954,9938,9911,9952,9974,9926,9920,9972,9983,9973,9917,9995,9973,9977,9947,9936,9975,9954,9932,9964,9972,9935,9946,9966 };
    int k = 3056;
    int arrSize = sizeof(num) / sizeof(num[0]);
    ret = maxFrequency(num, arrSize, k);
    printf("ret = %d\n", ret);
    assert(ret == 73);
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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define bool int
#define true 1
#define false 0

bool isCovered(int** ranges, int rangesSize, int* rangesColSize, int left, int right){
    *rangesColSize = 2;
    for (int i = left; i <= right; i++) {
        int flag = false;
        for (int j = 0; j < rangesSize; j++) {
            if (i >= ranges[j][0] && i <= ranges[j][1]) {
                flag = true;
                break;
            }
        }
        if (flag == false) {
            return false;
        }
    }
    return true;
}

void test01()
{
    int vec0[] = {1, 2};
    int vec1[] = {3, 4};
    int vec2[] = {5, 6};
    int rangeSize = 3;
    int** ranges = (int**)malloc(sizeof(int*) * rangeSize);
    int rangesColSize = 2;
    ranges[0] = vec0;
    ranges[1] = vec1;
    ranges[2] = vec2;
    int left = 2;
    int right = 5;

    bool ret = isCovered(ranges, 3, &rangesColSize, left, right);
    printf("ret = %d\n", ret);
    assert(ret == 1);
}

void test02()
{
    int vec0[] = {1, 10};
    int vec1[] = {10, 20};
    int rangeSize = 2;
    int** ranges = (int**)malloc(sizeof(int*) * rangeSize);
    int rangesColSize;
    ranges[0] = vec0;
    ranges[1] = vec1;
    int left = 21;
    int right = 21;

    bool ret = isCovered(ranges, rangeSize, &rangesColSize, left, right);
    printf("ret = %d\n", ret);
    assert(ret == 0);
}

int main()
{
    test01();
    test02();
    return 0;
}

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <assert.h>


void printArr(int* arr, int arrSize)
{
    printf("\n{");
    for(int i = 0; i < arrSize; i++) {
        printf("%d\t", arr[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("}\n");
}

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int* smallestK(int* arr, int arrSize, int k, int* returnSize)
{
    *returnSize = k;
    qsort(arr, arrSize, sizeof(int), cmp);
    int* res = (int*)malloc(sizeof(int) * k);
    memset(res, 0, k);
    memcpy(res, arr, k * sizeof(int));

    return res;
}

void test01()
{
    int arr[] = { 1, 3, 5, 7, 2, 4, 6, 8 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    int resultSize = 0;
    int* result = smallestK(arr, arrSize, k, &resultSize);
    int expectRes[4] = { 1, 2, 3, 4 };
    int expectResSize = sizeof(expectRes) / sizeof(expectRes[0]);
    assert(expectResSize == resultSize);
    if (memcmp(expectRes, result, resultSize * sizeof(int)) == 0) {
        printf("ok\n");
    } else {
        printf("errro\n");
    }
}

int main()
{
    test01();
    return 0;
}

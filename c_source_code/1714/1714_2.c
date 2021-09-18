#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

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

void Insert(int* Heap, int X, int* Size){
    int i;
    for(i = ++(*Size); Heap[i/2] > X; i /= 2)   //上滤
        Heap[i] = Heap[i/2];
    Heap[i] = X;
}

int DeleteMin(int* Heap, int* Size){
    int i, Child;
    int Min = Heap[1];
    int Last = Heap[(*Size)--];    //记下最后一个值
    for (i = 1; i * 2 <= (*Size); i = Child) {    //下滤
        Child = 2 * i;
        if (Child != (*Size) && Heap[Child] > Heap[Child+1]) {
            Child++;
        }
        if (Last > Heap[Child]) {
            Heap[i] = Heap[Child];
        } else {
            break;
        }
    }
    Heap[i] = Last;
    return Min;
}

int* smallestK(int* arr, int arrSize, int k, int* returnSize){
    int* res = (int*)malloc(k * sizeof(int));
    *returnSize = k;
    int* Heap = (int*)malloc((arrSize + 1) * sizeof(int));
    Heap[0] = INT_MIN;  //设置哨兵结点
    int Size = 0;

    for(int i = 0; i < arrSize; i++)
        Insert(Heap, arr[i], &Size);

    for(int i = 0; i < k; i++)
        res[i] = DeleteMin(Heap, &Size);
        
    free(Heap);
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

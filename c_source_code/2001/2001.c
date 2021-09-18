#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int cmp(const void* a, const void* b)
{
    return (*(double*)a > *(double*)b) ;
}

long long interchangeableRectangles(int** rectangles, int rectanglesSize, int* rectanglesColSize)
{
    double* res = (double*)malloc(sizeof(double) * rectanglesSize);
    for (int i = 0; i < rectanglesSize; i++) {
        res[i] = (double)rectangles[i][0] / rectangles[i][1];
    }
    qsort(res, rectanglesSize, sizeof(double), cmp);
    long long sum = 0;
    long long count = 0;
    for (int i = 0; i < rectanglesSize - 1; i++) {
        if (res[i] == res[i+1]) {
            count++;
        } else {
            sum += count * (count + 1) / 2;
            count = 0;
        }
    }
    if (count > 0) {
        sum += count * (count + 1) / 2;
    }
    free(res);
    return sum;
}

void test01()
{
    int array0[] = {4, 8};
    int array1[] = {3, 6};
    int array2[] = {10, 20};
    int array3[] = {15, 30};
    int *tmp[] = { array0, array1, array2, array3};

    int col = 2;
    long long expectRes = 6;
    long long res = interchangeableRectangles((int**)tmp, 4, &col);
    assert(res == expectRes);
}

void test02()
{
    int array0[] = {1, 7};
    int array1[] = {2, 8};
    int array2[] = {8, 8};
    int array3[] = {2, 5};
    int array4[] = {2, 8};
    int array5[] = {7, 4};
    int *tmp[] = { array0, array1, array2, array3, array4, array5};
    int col = 2;
    long long expectRes = 1;
    long long res = interchangeableRectangles((int**)tmp, 6, &col);
    assert(res == expectRes);
}

loid test03()
{
//    int array0[] = {1, 7};
//    int array1[] = {2, 8};
//    int array2[] = {8, 8};
//    int array3[] = {2, 5};
//    int array4[] = {2, 8};
//    int array5[] = {7, 4};
    int *tmp[] = { {1,7}, { 2,8}, {8,8}, {2,5}, {2,8}, {7,4} };
    int col = 2;
    long long expectRes = 1;
    long long res = interchangeableRectangles((int**)tmp, 6, &col);
    assert(res == expectRes);
}
int main()
{
    test01();
    test02();
    test03();

    return 0;
}

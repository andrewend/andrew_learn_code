#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int maxNum = n * n;
    int curNum = 1;
    int** matrix = malloc(sizeof(int*) * n);
    *returnSize = n;
    *returnColumnSizes = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(sizeof(int) * n);
        memset(matrix[i], 0, sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }

    int row = 0, column = 0;
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 右下左上
    int directionIndex = 0;
    while (curNum <= maxNum) {
        matrix[row][column] = curNum;
        curNum++;
        int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
        if (nextRow < 0 || nextRow >= n || nextColumn < 0 || nextColumn >= n || matrix[nextRow][nextColumn] != 0) {
            directionIndex = (directionIndex + 1) % 4;  // 顺时针旋转至下一个方向
        }
        row = row + directions[directionIndex][0];
        column = column + directions[directionIndex][1];
    }
    return matrix;
}

void test1()
{
    int n = 3;
    int returnSize = 0;
    int* returnColumnSizes = malloc(sizeof(int *) * n);
    int ** res = generateMatrix(n, &returnSize, &returnColumnSizes);
    printf("returnSize = %d\n", returnSize);
    for (int i = 0; i < n; i++) {
        printf("returnColumnSizes: %d\n", returnColumnSizes[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("res[i][j] = %d \n", res[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    test1();
    return 0;
}

/*
 * 一个班级里有 n 个学生，编号为 0 到 n - 1 。每个学生会依次回答问题，编号为 0 的学生先回答，然后是编号为 1 的学生，以此类推，直到编号为 n - 1 的学生，然后老师会重复这个过程，重新从编号为 0 的学生开始回答问题。 给你一个长度为 n 且下标从 0 开始的整数数组 chalk 和一个整数 k 。一开始粉笔盒里总共有 k 支粉笔。当编号为 i 的学生回答问题时，他会消耗 chalk[i] 支粉笔。如果剩余粉笔数量 严格小于 chalk[i] ，那么学生 i 需要 补充 粉笔。 
 请你返回需要 补充 粉笔的学生 编号 。
*/
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define FALSE   0 
#define TRUE    1

int getSum(const int* chalk, int chalkSize, int k, int* sum, int* number)
{
    int allSum = 0;
    for (int i = 0; i < chalkSize; i++) {
        allSum += chalk[i];
        if (allSum > k) {
            *sum = allSum;
            *number = i;
            return -1;
        }
    }
    *sum = allSum;
    return 0;
}

int chalkReplacer(int* chalk, int chalkSize, int k)
{
    int sum = 0;
    int isLess;
    int number;
    int ret = getSum(chalk, chalkSize, k, &sum, &number);
    if (ret != 0) {
        return number;
    }
    k = k % sum;

    ret = getSum(chalk, chalkSize, k, &sum, &number);
    if (ret != 0) {
        return number;
    }
    return number;
}

void test01()
{
    int chalk[] = {5, 1, 5};
    int chalkSize = sizeof(chalk) / sizeof(chalk[0]);
    int k = 22;

    int res = chalkReplacer(chalk, chalkSize, k);
    assert(res == 0);
}

void test02()
{
    int chalk[] = {3, 4, 1, 2};
    int chalkSize = sizeof(chalk) / sizeof(chalk[0]);
    int k = 25;

    int res = chalkReplacer(chalk, chalkSize, k);
    assert(res == 1);
}

int main()
{
    test01();
    test02();

    return 0;
}    

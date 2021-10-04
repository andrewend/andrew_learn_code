int cmp(const void* a, const void* b)
{
    int* ap = *(int**)a;
    int* bp = *(int**)b;

    if (ap[0] == bp[0]) {
        return ap[1] > bp[1];
    }

    return ap[0] > bp[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    int** res = (int**)malloc(sizeof(int*) * intervalsSize);
    for (int i = 0; i < intervalsSize; i++) {
        res[i] = (int*)malloc(sizeof(int) * intervalsColSize[i]);
    }

    qsort(intervals, intervalsSize, sizeof(int) * intervalsColSize[0], cmp);

    int i, k;
    res[0] = intervals[0];
    for (i = 0, k = 0; i < intervalsSize; i++) {
        if (res[k][1] < intervals[i][0]) {
            res[++k] = intervals[i];
        } else {
            res[k][1] = fmax(res[k][1], intervals[i][1]);
        }
    }
    *returnSize = k + 1;
    *returnColumnSizes = intervalsColSize;
    return res;
}

int cmp(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}

int* majorityElement(int* nums, int numsSize, int* returnSize){

    qsort(nums, numsSize, sizeof(int), cmp);
    int* res = malloc(sizeof(int) * numsSize);
    int size = 0;
    int tmp = 0;
    int count = 1;
    tmp = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i-1]) {
            count++;
        } else {
            if (count > numsSize / 3) {
                res[size++] = count;
            }
            count = 1;
        }
    }
    *returnSize = size;
    return res;
}


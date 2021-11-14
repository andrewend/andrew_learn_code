int cmp(const void* a, const void* b)
{
    char aStr[101];
    char bStr[101];
    sprintf(aStr, "%d%d", *(int*)a, *(int*)b);
    sprintf(bStr, "%d%d", *(int*)b, *(int*)a);
    return strcmp(aStr, bStr);
}
char * largestNumber(int* nums, int numsSize){
    if (numsSize == 0) {
        return "0";
    }
    qsort(nums, numsSize, sizeof(int), cmp);

    char* p = malloc(sizeof(char) * 1001);
    memset(p, 0x0, 1001);
    char* res = p;

    char str[101];
    for(int i = 0; i < numSize; i++) {
        sprintf(str, "%d", nums[i]);
        strcat(res, str);
    }

    return p;
}

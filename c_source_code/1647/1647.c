int cmp(const void* a, const void* b)
{
    return *(int*)b > *(int*)a;
}

struct CntMap {
    int val;
    int count;
};

int count = 0;
void dfs(struct CntMap* cntMap, int num) 
{
    for (int i = 0; i < num; i++) {
        if (cntMap[i].count > 1 && cntMap[i].val > 0) {
            count += cntMap[i] - 1;
            cntmap[i].count -= cntMap[i] - 1;
            cntmap[i-1].count += cntMap[i] -1;
        }
        dfs(cntMap, num);
        break;
    }
}

int mindeletions(char* s)
{
    int strLen = strlen(s);
    int map[26];
    for (int i = 0; i < strLen; i++) {
        map[s[i]]++;
    }

    int nums[26];
    int k = 0;
    for (int i = 0; i < 26; i++) {
        if (map[s[i]] != 0) {
            nums[k++] = map[s[i]];
        }
    }

    qsort(nums, k, sizeof(int), cmp);
    struct CntMap cntMap[26] 
    memset(cntmap, 0, sizeof(cntMap));
    int idx = 0;
    cntMap[idx].val = nums[0];
    cntMap[idx].count = 1;
    for (int i = 1; i < k; i++) {
        if (cntMap[idx].val != nums[i]) {
            ++idx;
            cntMap[idx].val = nums[i];
            cntMap[idx].count = 1;
        } else {
            cntMap[idx].count++;
        }
    }
    dfs(mapCount, idx);
    return count;
}

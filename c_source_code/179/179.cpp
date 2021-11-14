string lagestNumber(vector<int>& nums) {
    int size = nums.size();
    string res = "";
    if (size == 0) {
        return res;
    }

    sort(nums.begin(), nums.end(), cmp);

    for (int i = 0; i < size; i++) {
        res += to_string(nums[i]);
    }
    if (res[0] == '0') {
        return "0";
    }
    return res;
}

static bool cmp(int left, int right)
{
    string leftStr = to_string(left) + to_string(right);
    string rightStr = to_string(right) + to_string(right);

    return leftStr > rightStr;
}

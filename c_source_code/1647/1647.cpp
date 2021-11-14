class Solution {
public:
    int count = 0;
    void dfs(unorderd_map<int, int> cntMap)
    {
        for (auto map : cntMap) {
            if (map.first > 0 && map.second > 1) {
                count += map.second - 1;
                cntMap[map.first] -= map.second - 1;
                cntMap[map.first-1] += map.second - 1;
                dfs(cntMap);
                break;
            }
        }
    }
    int minDeletions(string s) {
        unordered_map<char, int> mapCount;
        for (int i = 0; i < s.size(); i++) {
            mapCount[s[i]]++;
        }
        vector<int> nums;
        for (auto map : mapCount) {
            nums.push_back(map.second);
        }

        sort(nums.begin(), nums.end(), greater<int>());
        unordered_map<int, int> cntMap;
        for (int i = 0; i < nums.size(); i++) {
            cntMap[nums[i]]++;
        }
        dfs(cntMap);
        return count;
    }

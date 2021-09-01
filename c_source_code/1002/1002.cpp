#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < strs.size(); i++) {
            string tempStr(strs[i]);
            sort(tempStr.begin(), tempStr.end());
            mp[tempStr].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for (auto tmpMap : mp) {
            res.push_back(tmpMap.second);
        }

        return res;
    }
};

void test1()
{
    Solution solution;
    vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat" };
    vector<vector<string>> res = solution.groupAnagrams(str);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << "\t" ;
        }
        cout << endl;
    }
}


int main()
{
    test1();

    return 0;
}

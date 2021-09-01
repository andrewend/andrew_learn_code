#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permut(vector<int>& nums) {
        vector<vector<int>> ret;
        do {
            ret.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));
        ret.erase(unique(ret.begin(), ret.end()), ret.end());

        return ret;
    }
};

void test1()
{
    vector<int> vec = { 1, 2, 2 };
    Solution solution;
    vector<vector<int>> res;
    res = solution.permut(vec);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << "\t";
        }
        cout << endl;
    }
}

void test2()
{
    vector<int> vec = { 1, 2, 2, 4, 5, 4 };
    Solution solution;
    vector<vector<int>> res;
    res = solution.permut(vec);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    test1();
    test2();

    return 0;
}

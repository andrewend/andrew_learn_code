#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> ret;

public:
    void backtrace(vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            res.push_back(ret);
        }
        if (target < 0) {
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            ret.push_back(candidates[i]);
            backtrace(candidates, target - candidates[i], i);
            ret.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrace(candidates, target, 0);
        return res;
    }
};

void test1()
{
    cout << __func__ << "\t" << __LINE__ << endl;
    Solution solution;
    vector<int> candidates = { 2, 3, 6, 7 };
    vector<vector<int>> res = solution.combinationSum(candidates, 7);
    for (int i = 0; i < res.size(); i++) {
        cout << "[\t"; 
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << "\t";
        }
        cout << "]\t" << endl;
    }
}

void test2()
{
    cout << __func__ << "\t" << __LINE__ << endl;
    Solution solution;
    vector<int> candidates = { 2, 3, 5  };
    vector<vector<int>> res = solution.combinationSum(candidates, 8);
    for (int i = 0; i < res.size(); i++) {
        cout << "[\t"; 
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << "\t";
        }
        cout << "]\t" << endl;
    }
}


int main()
{
    test1();
    test2();

    return 0;
}

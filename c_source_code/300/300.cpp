//示例 1：
//
//输入：nums = [10,9,2,5,3,7,101,18]
//输出：4
//解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
//示例 2：
//
//输入：nums = [0,1,0,3,2,3]
//输出：4
//示例 3：
//
//输入：nums = [7,7,7,7,7,7,7]
//输出：1
#include <iostream>
#include <cstring>
#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    void print(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << "\t";
        }
        cout << endl;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        sort(dp.begin(), dp.end());
        //print(dp);
        return dp[n-1];
    }
};

void test01()
{
    vector<int> nums = { 10,9,2,5,3,7,101,18 };
    Solution solut;
    int res = solut.lengthOfLIS(nums);
    assert(res == 4);
}

void test02()
{
    vector<int> nums = { 0,1,0,3,2,3 };
    Solution solut;
    int res = solut.lengthOfLIS(nums);
    assert(res == 4);
}

void test03()
{
    vector<int> nums = { 7,7,7,7,7,7,7 };
    Solution solut;
    int res = solut.lengthOfLIS(nums);
    assert(res == 1);
}

int main()
{
    test01();
    test02();
    test03();

    return 0;
}

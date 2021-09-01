#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxRes = nums[0];
        int maxLen = nums.size();
        int sum = 0;
        for (int i = 1; i <= maxLen; i++) {
            sum = 0;
            for (int k = 0; k + i < maxLen; k++) {
                for (int j = 0; j < maxLen && j < i; j++) {
                        sum += nums[k + j];
                }
                maxRes = max(sum, maxRes);
                cout << maxRes << endl;
            }
        }
        return maxRes;
    }
};

void test1()
{
    Solution solution;
    vector<int> vec = { -2,1,-3,4,-1,2,1,-5,4 };
    int maxNum = solution.maxSubArray(vec);

    cout << "maxNum: " << maxNum << endl;
    assert(maxNum == 6);
}

int main()
{
    test1();

    return 0;
}

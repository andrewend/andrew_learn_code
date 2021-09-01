#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        return backtrace(0, nums);
    }

    bool backtrace(int idx, vector<int>& nums) {
        if (idx + nums[idx] >= nums.size()) {
            cout << "idx: " << idx << " " << nums[idx] << endl;
            return true;
        }

        for (int i = 1; i <= nums[idx] && i + idx < nums.size(); i++) {
#if 0
            if (idx + i == 4) {
                cout << i << ":" << idx << endl;
            }
#endif
            if (backtrace(idx + i, nums) == true) {
                //cout << i << " idx: " << idx << " " << nums[idx] << endl;
                return true;
            }
        }
        return false;
    }

};

void test1()
{
    Solution solution;
    vector<int> nums = { 2, 3, 1, 1, 4 };
    bool ret = solution.canJump(nums);
    cout << ret << endl;
    assert(ret == true);
}

void test2()
{
    Solution solution;
    vector<int> nums = { 3, 2, 1, 0, 4 };
    bool ret = solution.canJump(nums);
    cout << ret << endl;
    assert(ret == false);
}

int main()
{
    test1();
//    test2();
    return 0;
}

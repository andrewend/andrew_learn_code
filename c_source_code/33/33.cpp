#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        for (int i = 0; i < sz; i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }

};

void test0()
{
    Solution solution;
    vector<int> vec = {4,5,6,7,0,1,2};
    int res = solution.search(vec, 0);
    cout << "res:" << res << endl;
    assert(res == 4);
}


int main()
{
    test0();
    
    return 0;
}

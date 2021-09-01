#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    int binary_search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else { 
                return mid;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int idx = binary_search(nums, target);
        if (idx == -1) {
            return 0;
        }
        cout << "idx:" << idx << endl;

        int left, right;
        left = right = idx;
        while (left >= 0 && nums[left] == target) {
            left--;
        }
        if (left != nums.size()) {
            left++;
        }

        while (right < nums.size() && nums[right] == target) {
            right++;
        }
        if (right != 0) {
            right--;
        }
        cout << "idx:" << idx << "left:" << left << "right:" << right << endl;

        return right - left + 1;

    }
};

void test01()
{
    Solution solution;
    vector<int> nums = { 5, 7, 7, 8, 8, 10 };
    int res = solution.search(nums, 8);
    cout << "res:" << res << endl;
    assert(res == 2);
}


void test02()
{
    Solution solution;
    vector<int> nums = { 5, 7, 7, 8, 8, 10 };
    int res = solution.search(nums, 6);
    cout << "res:" << res << endl;
    assert(res == 0);
}

void test03()
{
    Solution solution;
    vector<int> nums = { 1 };
    int res = solution.search(nums, 1);
    cout << "res:" << res << endl;
    assert(res == 1);
}

void test04()
{
    Solution solution;
    vector<int> nums = { 1,4 };
    int res = solution.search(nums, 4);
    cout << "res:" << res << endl;
    assert(res == 1);
}

int main()
{
    test01();
    test02();
    test03();
    test04();

    return 0;
}


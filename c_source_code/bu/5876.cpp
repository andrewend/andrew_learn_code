#include <iostream>
#include <vector>

using namespace std;

void fillvec(vector<int>& nums, vector<int>& vecLeft, vector<int>& vecRight) {
    for (int i = 1; i < nums.size(); i++) {
        vecLeft[i] = max(nums[i], nums[i+1]);
    }

    for (int i = nums.size() -2; i >=0; i--) {
        vecRight[i] = min(nums[i], nums[i+1]);

    }
}

int sumOfBeauties(vector<int>& nums) {
    int res = 0;
    vector<int> vecLeft(nums), vecRight(nums);
    fillvec(nums, vecLeft, vecRight);

    for (int i = 1; i < nums.size() - 1; i++) {
        if (nums[i] > vecLeft[i-1] && nums[i] < vecRight[i+1]) {
            res += 2;
        } else if (nums[i] > nums[i-1] && nums[i] < nums[i+1]) {
            res++;
        }
    }
    return res;
}

void test03()
{
    vector<int> vec = { 3, 2, 1};
    cout << sumOfBeauties(vec) << endl;
}
void test02()
{
    vector<int> vec = { 2, 4, 6, 4};
    cout << sumOfBeauties(vec) << endl;
}

void test01()
{
    vector<int> vec = { 1, 2, 3};
    cout << sumOfBeauties(vec) << endl;
}

int main()
{
    test01();
    test02();
    test03();

    return 0;
}

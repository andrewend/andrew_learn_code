#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    void badnextPermutation(vector<int>& nums) {
        int sz = nums.size();
        int flag = false;
        for (int i = sz - 1; i > 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                    return;
                }
            }
        }
        swap(nums[sz-1], nums[0]);
    }

    void nextPermutation(vector<int>& nums) {
        int i = nums.size() -2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
                i--;
        }
        if (i >= 0) {
            int j = nums.size() -1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }

};

void test5()
{
    vector<int> input = { 1, 3, 2 };
    Solution solution;
    solution.nextPermutation(input);
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << ",\t";
    }
    cout << endl;

    vector<int> res = { 2, 1, 3 };
    assert(input == res);
}

void test4()
{
    vector<int> input;
    for (int i = 0; i < 100; i++) {
        input.push_back(rand());
    }
    Solution solution;
    solution.nextPermutation(input);
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << ",\t";
    }
    cout << endl;

    //vector<int> res = { 1 };
    //assert(input == res);
}


void test3()
{
    vector<int> input = { 1 };
    Solution solution;
    solution.nextPermutation(input);
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << ",\t";
    }
    cout << endl;

    vector<int> res = { 1 };
    assert(input == res);
}


void test2()
{
    vector<int> input = { 1, 1, 5 };
    Solution solution;
    solution.nextPermutation(input);
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << ",\t";
    }
    cout << endl;

    vector<int> res = { 1, 5, 1};
    assert(input == res);
}

void test1()
{
    vector<int> input = { 1, 2, 3};
    Solution solution;
    solution.nextPermutation(input);
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << ",\t";
    }
    cout << endl;

    vector<int> res = { 1, 3, 2};
    assert(input == res);
}

void test0()
{
    vector<int> input = { 3, 2, 1};
    Solution solution;
    solution.nextPermutation(input);
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << ",\t";
    }
    cout << endl;

    vector<int> res = { 1, 2, 3};
    assert(input == res);
}

int main()
{
    test0();
    test1();
    test2();
    test3();
    //test4();
    test5();


    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int vecSize = citations.size();
//        sort(citations.begin(), citations.end());

#if 0
        for (int i = 0; i < vecSize; i++) {
            cout << citations[i] << endl;
        }
#endif
        int left = 0;
        int right = vecSize;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            int t = 0; 
            for (auto& x : citations) {
                if (x >= mid) {
                    t++;
                }
            }
            if (t < mid) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return left;
    }

};

void test1()
{
    vector<int> cit = { 3, 0, 6, 1, 5};
    Solution solution;
    int ret = solution.hIndex(cit);
    cout << "ret = " << ret << endl;
    assert(ret==3);
}

void test2()
{
    vector<int> cit = { 0 };
    Solution solution;
    int ret = solution.hIndex(cit);
    cout << "ret = " << ret << endl;
    assert(ret == 0);
}

void test3()
{
    vector<int> cit = { 1,1,1,1,1,1 };
    Solution solution;
    int ret = solution.hIndex(cit);
    cout << "ret = " << ret << endl;
    assert(ret == 1);
}

void test4()
{
    vector<int> cit = { 4,4,0,0 };
    Solution solution;
    int ret = solution.hIndex(cit);
    cout << "ret = " << ret << endl;
    assert(ret == 2);
}

int main()
{
#if 1
    test1();
    test2();
    test3();
#endif
    test4();
    return 0;
}

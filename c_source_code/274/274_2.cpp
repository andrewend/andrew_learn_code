#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int vecSize = citations.size();
        sort(citations.begin(), citations.end());

#if 0
        for (int i = 0; i < vecSize; i++) {
            cout << citations[i] << endl;
        }
#endif
        int h = 0;
        int i = vecSize - 1;
        while(i >= 0 && h < citations[i]) {
            h++;
            i--;
        }
        return h;
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

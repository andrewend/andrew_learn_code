#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int vecSize = citations.size();
        if (vecSize == 0) {
            return 0;
        }
        //sort(citations.begin(), citations.end(), greater<>());
        sort(citations.begin(), citations.end(), greater<int>());

#if 0
        for (int i = 0; i < vecSize; i++) {
            cout << citations[i] << endl;
        }
#endif
        
        for (int i = 0; i < vecSize; i++) { 
            int hIdx = min(vecSize, citations[i]);
            if (hIdx < i) {
                return i;
            }
            int count = 0;
            for (int j = 0; j < vecSize; j++) {
                if(hIdx <= citations[j]) {
                    count++;
                }
            }
            if (count >= hIdx) {
                return hIdx;
            }

            //if (count <= i) {
            //    return count;
            //}
        }
        return 0;
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

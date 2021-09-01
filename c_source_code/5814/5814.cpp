#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int step = 0;

        if (rungs[0] > dist) {
            step +=  (rungs[0] - 0 - 1) / dist;
        }

        for (int i = 0; i < rungs.size() - 1; i++) {
            if (rungs[i+1] - rungs[i] > dist) {
                int add = (rungs[i+1] - rungs[i] - 1) / dist;
                step += add;
            } 
        }
        return step;
    }
};

void test01() {
    Solution solution;
    vector<int> rungs = { 3, 4, 6, 7 };
    int dist = 2;
    int res = solution.addRungs(rungs, dist);
    cout << "res:" << res << endl;
    assert(res == 1);
}

void test02() {
    Solution solution;
    vector<int> rungs = { 2, 4, 6, 7 };
    int dist = 2;
    int res = solution.addRungs(rungs, dist);
    cout << "res:" << res << endl;
    assert(res == 0);
}

void test05() {
    Solution solution;
    vector<int> rungs = { 5 };
    int dist = 10;
    int res = solution.addRungs(rungs, dist);
    cout << "res:" << res << endl;
    assert(res == 0);
}

void test03() {
    Solution solution;
    vector<int> rungs = { 1, 3, 5, 10 };
    int dist = 2;
    int res = solution.addRungs(rungs, dist);
    cout << "res:" << res << endl;
    assert(res == 2);
}

void test04() {
    Solution solution;
    vector<int> rungs = { 3, 6, 8, 10 };
    int dist = 3;
    int res = solution.addRungs(rungs, dist);
    cout << "res:" << res << endl;
    assert(res == 0);
}
int main()
{
    test01();
    test02();
    test03();
    test04();
    test05();

    return 0;
}




#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

class Solution {
public:
	int coutTriples(int n) {
		int count = 0;
		for (int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                for (int k = j+1; k <= n; k++) {
                    if (i * i + j * j == k * k) {
                        //cout << i << "\t" << j << "\t" << k << endl;
                        count++;
                    }
                }
            }
        }
        return (2 * count);
    }
};


void test4()
{
    Solution solution;
    int res = solution.coutTriples(250);
    cout << res << endl;
    assert(res == 330);
}

void test3()
{
    Solution solution;
    int res = solution.coutTriples(100);
    cout << res << endl;
    assert(res == 104);
}

void test1()
{
    Solution solution;
    int res = solution.coutTriples(10);
    cout << res << endl;
    assert(res == 4);
}

void test0()
{
    Solution solution;
    int res = solution.coutTriples(5);
    cout << res << endl;
    assert(res == 2);
}

int main()
{

    test0();
    test1();
    test3();
    test4();


    return 0;
}

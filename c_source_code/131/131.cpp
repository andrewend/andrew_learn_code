#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    vector<string> vec;
    vector<vector<string>> res;

    void dfs(string s, int idx)
    {
        int strLen = s.size();
        if (idx == strLen) {
            res.push_back(vec);
            return;
        }
        for (int i = idx; i < strLen; i++) {
            string str = s.substr(idx, i - idx + 1);
            if (isCirclStr(str)) {
                vec.push_back(str);
                dfs(s, idx +1);
                vec.pop_back();
            } 
        }
    }

    bool isCirclStr(string s)
    {
        int left = 0; 
        int right = s.size() - 1;
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }

        return true;
    }

    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return res;
    }
};

void test01()
{
    Solution solut;
    string s("aba");
    bool ret= solut.isCirclStr(s);
    cout << "ret = %d" <<  ret << endl;
}

int main()
{
    test01();

    return 0;
}

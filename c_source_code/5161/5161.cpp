#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        char map[26] = { 0 };
        
        for (int j = 0; j < brokenLetters.size(); j++) {
            map[brokenLetters[j] - 'a']++;
        }
        
        int count = 0;
        int flag = true;
        for (int i = 0; i < text.size(); i++) {
            flag = true;
            while(text[i] != ' ' && i < text.size()) {
                if (map[text[i] - 'a']) {
                    flag = false;
                }
                i++;
            }
            if (flag == true) {
                count++;
            }
        }

        return count;
    }
};

void test01()
{
	Solution solution;
    const string text("hwllo world");
    const string brokenLetters("ad");
	int res = solution.canBeTypedWords(text, brokenLetters);
	cout << "res:\t" << res << endl;
    assert(res == 1);
}

void test02()
{
	Solution solution2;
    string text1("leet code");
    string brokenLetters1("lt");
	int res2 = solution2.canBeTypedWords(text1, brokenLetters1);
	cout << "res:\t" << res2 << endl;
    assert(res2 == 1);
}

void test03()
{
	Solution solution;
    string text("leet code");
    string brokenLetters("e");
	int res = solution.canBeTypedWords(text, brokenLetters);
	cout << "res:\t" << res << endl;
    assert(res == 0);
}
int main()
{
	test02();
	test01();
	test03();

	return 0;
}

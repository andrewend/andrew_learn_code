#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s)
{
    int left, right;
    left = right = 0;
    int strSize = strlen(s);
    if (strSize == 0) {
        return 0;
    }
    int map[128] = { 0 };
    int max = 0;
    while (right < strSize) {
        if (map[s[right]] == 0) {
            map[s[right]]++;
        } else {
            max = (right - left) > max ? (right - left) : max;
            left = right;
        }
        right++;
    }
    max = (right - 1 - left) > max ? (right - left) : max;
    return max;
}

void test01()
{
    char s1[] = "abcabcbb";
    int res = lengthOfLongestSubstring(s1);
    assert(res == 3);
}

void test02()
{
    char s1[] = "bbbbbb";
    int res = lengthOfLongestSubstring(s1);
    assert(res == 1);
}

void test03()
{
    char s1[] = "pwwkew";
    int res = lengthOfLongestSubstring(s1);
    assert(res == 3);
}

void test04()
{
    char s1[] = "";
    int res = lengthOfLongestSubstring(s1);
    assert(res == 0);
}

void test05()
{
    char s1[] = " ";
    int res = lengthOfLongestSubstring(s1);
    assert(res == 1);
}
int main()
{
    printf("yangbin test\n");
//    test01();
//    test02();
//    test03();
//    test04();
    test05();

    return 0;
}

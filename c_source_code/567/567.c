//给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。
//
//换句话说，s1 的排列之一是 s2 的 子串 。
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define true 1
#define false 0

int checkInclusion(char * s1, char * s2){
    int left, right;
    left = right = 0;
    int map[26] = { 0 };
    int tmpMap[26] = { 0 };
    int s1Len = strlen(s1);
    int s2Len = strlen(s2);
    if (s2Len < s1Len) {
        return false;
    }

    for (int i = 0; i < s1Len; i++) {
        map[s1[i] - 'a']++;
        tmpMap[s2[i] - 'a']++;
    }
    right = left + s1Len - 1;
    while(right < s2Len) {
        if (memcmp(map, tmpMap, 26 * sizeof(int)) == 0) {
            return true;
        }
        tmpMap[s2[left] - 'a']--;
        left++;
        right++;
        if (right < s2Len) {
            tmpMap[s2[right] - 'a']++;
        }
        //printf("right:%d, s2len: %d, s2[right] - 'a':%d\n", right, s2Len, s2[right] - 'a');
    }
    return false;
}

void test01()
{
    char s1[] = "ab";
    char s2[] = "eidbaooo";
    int res = checkInclusion(s1, s2);
    assert(res == 1);
}

void test02()
{
    char s1[] = "ab";
    char s2[] = "eidboaoo";
    int res = checkInclusion(s1, s2);
    assert(res == 0);
}

void test03()
{
    char s1[] = "ab";
    char s2[] = "eidboaooba";
    int res = checkInclusion(s1, s2);
    assert(res == 1);
}
int main()
{
 //   test01();
    test02();
//    test03();

    return 0;
}

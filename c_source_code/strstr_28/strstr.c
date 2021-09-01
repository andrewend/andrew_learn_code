//实现 strStr() 函数。
//
//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。
//
//
//
//说明：
//
//当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
//
//对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。
//
//
//
//示例 1：
//
//输入：haystack = "hello", needle = "ll"
//输出：2
//
//示例 2：
//
//输入：haystack = "aaaaa", needle = "bba"
//输出：-1
//
//示例 3：
//
//输入：haystack = "", needle = ""
//输出：0

#include <stdio.h>
#include <string.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

int strStr1(const char* haystack, const char* needle)
{
    int ret = strstr(haystack, needle) - &haystack[0];
    if (ret < 0) {
        return -1;
    }
    return ret;
}

int strStr(const char* haystack, const char* needle)
{
    int subStrLen = strlen(needle);
    if (subStrLen == 0) {
        return 0;
    }
    char startCh = needle[0];

    for (const char* p = &haystack[0]; *p != '\0'; p++) {
        if (*p != startCh) {
            continue;
        }

        int flag = TRUE;
        const char* q = &needle[0];
        for (int i = 0; i < subStrLen; i++) {
            if (p[i] != q[i]) {
                flag = FALSE;
                break;
            }
        }
        if (flag == TRUE) {
            return (p - &haystack[0]);
        }
    }
    return -1;
}

void test_strstr()
{
    const char haystack[] = "RUNOOB";
    const char needle[] = "NOOB";
    int ret2 = strStr1(haystack, needle);
    int ret = strStr(haystack, needle);
    //printf("RUNOOB substring NOOB is: %s\n", ret);
    //int pos = ret - &haystack[0];
    //printf("pos:%d\n", pos);
    assert(ret == ret2);
}

void test_strstr1()
{
    const char haystack[] = "RUNOOB";
    const char needle[] = "";
    int ret;
    ret = strStr(haystack, needle);
    assert(ret == 0);
}
int main()
{
    test_strstr();
    test_strstr1();

    return 0;
}


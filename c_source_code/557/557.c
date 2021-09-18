#include <stdio.h>
#include <assert.h>
#include <string.h>

void reversWord(char* start, char* end)
{
    char ch;
    while (start < end) {
        ch = *start;
        *start = *end;
        *end = ch;
        start++;
        end--;
    }
}

char* reverseWords(char* s)
{
    char* p = s;
    char* start;
    char* end;
    while(*p != '\0') {
        start = p;
        end = p;
        while (*end != ' ' && *end != '\0') {
            end++;
        }
        reversWord(start, end - 1);
        /*
         * -fsanitize=address
         * 用户态内存错误检测，可以被环境变量ASAN_OPTIONS控制具体行为
         */
        if (*end == '\0') {
            break;
        }

        p = end + 1;
    }
    return s;
}

void test01()
{
    char str[] = "Let's take LeetCode contest";
    char reverseStr[] = "s'teL ekat edoCteeL tsetnoc";
    char* res = reverseWords(str);
    assert(strcmp(reverseStr, res) == 0);
}

int main()
{
    test01();

    return 0;
}

#include <stdio.h>
#include <assert.h>
#include <string.h>

void swap(char* a, char* b)
{
    char tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

char* reversePrefix(char* word, char ch)
{
    int end = 0;
    for (int i = 0; word[i] != '\0'; ++i) {
        if (word[i] == ch) {
            end = i;
            break;
        }
    }
    if (end == 0) {
        return word;
    }
    for (int i = 0; i < (end+1) / 2; ++i) {
        swap(&word[i], &word[end - i]);
    }
    return word;
}

void test01()
{
    char word[] = "abcdefd";
    char ch = 'd';
    char* res = reversePrefix(word, ch);
    char resExpect[] = "dcbaefd";
    printf("res:%s\n", res);
    assert(strcmp(res, resExpect) == 0);
}

void test02()
{
    char word[] = "xyxzxe";
    char ch = 'z';
    char* res = reversePrefix(word, ch);
    char resExpect[] = "zxyxxe";
    assert(strcmp(res, resExpect) == 0);
}

void test03()
{
    char word[] = "abcd";
    char ch = 'z';
    char* res = reversePrefix(word, ch);
    char resExpect[] = "abcd";
    assert(strcmp(res, resExpect) == 0);
}

int main()
{
    test01();
    test02();
    test03();

    return 0;
}


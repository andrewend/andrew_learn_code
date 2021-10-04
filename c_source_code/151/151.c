#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void swap(char* ch1, char* ch2)
{
    char ch = *ch1;
    *ch1 = *ch2;
    *ch2 = ch;
}

void reverse(char* s)
{
    int strLen = strlen(s);
    int left = 0;
    int right = strLen - 1;
    while (left < right) {
        swap(&s[left], &s[right]);
        left++;
        right--;
    }
}

char * reverseWords(char * s){
    int strLen = strlen(s);
    char* res = (char*)malloc(strLen+1);
    char* word = (char*)malloc(strLen+1);
    int i = strLen - 1;
    int wordStart = 0;
    int pos = 0;
    char* p = res;

    while(i >= 0) {
        //printf("%s\n", s);
        memset(word, 0, strLen+1);
        pos = 0;
        
        if (s[i] == ' ') {
            i--;
            continue;
        }
        //printf("s[%d] = %c\n", i, s[i]);
        while (i >= 0 && s[i] != ' ' ) {
            //printf("1 pos = %d, s[%d] = %c\n", pos, i, s[i]);
            word[pos++] = s[i--];
            //printf("2 pos = %d, s[%d] = %c\n", pos, i, s[i]);
        }
        //printf("=====pos:%d\n", pos);
        word[pos] = '\0';
        printf("1.wordlen[%d]:[%s]\n", pos, word);
        reverse(word);
        printf("2.wordlen[%d]:[%s]\n", pos, word);
        memcpy(p, word, pos);
        p += pos;

        if (i < 0) {
            break;
        }

        *p++ = ' ';
        i--;
    }
    if (*(--p) == ' ') {
        *p = '\0';
    } else {
        *(++p) = '\0';
    }
    
    printf("[%s]\n", res);
    free(word);
    return res;
}

void test01()
{
    char str[] = "the sky is blue";
    char* res = reverseWords(str);
    char* expectRes = "blue is sky the";
    printf("[%s]\n", res);
    assert(strcmp(expectRes, res) == 0);
    free(res);
}

void test02()
{
    char str[] = "  hello world  ";
    char* res = reverseWords(str);
    char* expectRes = "world hello";
    printf("[%s]\n", res);
    assert(strcmp(expectRes, res) == 0);
    free(res);
}

void test03()
{
    char str[] = "a good   example";
    char* res = reverseWords(str);
    char* expectRes = "example good a";
    printf("[%s]\n", res);
    assert(strcmp(expectRes, res) == 0);
    free(res);
}

void test04()
{
    char str[] = "  Bob    Loves  Alice   ";
    char* res = reverseWords(str);
    char* expectRes = "Alice Loves Bob";
    printf("[%s]\n", res);
    assert(strcmp(expectRes, res) == 0);
    free(res);
}

void test05()
{
    char str[] = "Alice does not even like bob";
    char* res = reverseWords(str);
    char* expectRes = "bob like even not does Alice";
    printf("[%s]\n", res);
    assert(strcmp(expectRes, res) == 0);
    free(res);
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

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

//#define printf(...)
#define MAX_LEN 4500
char tmp[MAX_LEN];
void countAndSayImp(int n, char* res)
{
    memset(tmp, 0, MAX_LEN);
    char* p = res;
    int k = 0;
    if (n == 1) {
        p[k++] = '1';
        p[k++] == '\0';
        return ;
    }
    countAndSayImp(n-1, res);
    int strLen = strlen(res);
 //   printf("---res:%s\n", res);
 //   printf("strLen:%d\n", strLen);
#if 1
    char data = 0;
    int i = 0; 
    int count = 0;
    k = 0;
   // printf("k:%d\n", k);
    while (i < strLen) {
        count = 1;
        data = res[i];
     //   printf("data:%c, %d\n", data, i);
        while (i < strLen - 1 && res[i+1] == res[i]) {
            count++;
            i++;
        }
        tmp[k++] = count + '0';
        tmp[k++] = data;
        i++;
    }
    tmp[k] = '\0';
  //  printf("k:%d\n", k);
   // printf("=tmp:%c, %c, %c\n", tmp[0], tmp[1], tmp[2]);
    memcpy(res, tmp, k+1);
    //printf("=res:%s\n", res);
#endif
}

char* countAndSay(int n){
   char* result = (char*)malloc(sizeof(char) * MAX_LEN);
   memset(result, 0x0, MAX_LEN);
   countAndSayImp(n, result);
   return result;
}

void test01()
{
    int n = 1;
    char* res = countAndSay(n);
    char resExpec[] = "1";
    printf("res:%s\n", res);
    assert(strcmp(res, resExpec) == 0);
    free(res);
}

void test02()
{
    int n = 2;
    char* res = countAndSay(n);
    char resExpec[] = "11";
    printf("res:%s\n", res);
    assert(strcmp(res, resExpec) == 0);
    free(res);
}
void test03()
{
    int n = 3;
    char* res = countAndSay(n);
    char resExpec[] = "21";
    printf("res:%s\n", res);
    assert(strcmp(res, resExpec) == 0);
    free(res);
}
void test04()
{
    int n = 4;
    char* res = countAndSay(n);
    char resExpec[] = "1211";
    printf("res:%s\n", res);
    assert(strcmp(res, resExpec) == 0);
    free(res);
}
void test05()
{
    int n = 5;
    char* res = countAndSay(n);
    char resExpec[] = "111221";
    printf("res:%s\n", res);
    assert(strcmp(res, resExpec) == 0);
    free(res);
}

void test06()
{
    int n = 6;
    char* res = countAndSay(n);
    char resExpec[] = "312211";
    printf("res:%s\n", res);
    assert(strcmp(res, resExpec) == 0);
    free(res);
}
void test07()
{
    int n = 30;
    char* res = countAndSay(n);
    char resExpec[] = "1211";
    printf("res:%s strlen:%ld\n", res, strlen(res));
    //assert(strcmp(res, resExpec) == 0);
    free(res);
}
int main()
{
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    test07();

    return 0;
}

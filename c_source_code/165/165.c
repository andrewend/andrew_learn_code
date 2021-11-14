#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define printf(...)
void print(int* arr, int num)
{
    printf("\n===num:%d=========\n", num);
    for (int i = 0; i < num; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n============\n");
}

void convertStrToArray(char* version, int* res, int* num)
{
    int strLen = strlen(version);
    char* v = version;
    char* p = (char*)malloc(strLen+1);
    int idx = 0;
    int k = 0;
    for (int i = 0; i < strLen; i++) {
        if (v[i] != '.') {
            p[k++] = v[i];
        } else {
            p[k++] = '\0';
            res[idx++] = atoi(p);
            k = 0;
        }
    }
    p[k++] = '\0';
    res[idx++] = atoi(p);
    *num = idx;
    free(p);

    return;
}

int res1[500];
int res2[500];

int compareVersion(char * version1, char * version2)
{
    int strLen1 = strlen(version1);
    int strLen2 = strlen(version2);
    //int* res1 = (int*)malloc(sizeof(int) * (strLen1 + 1) / 2);
    int num1;
    convertStrToArray(version1, res1, &num1);

    int num2;
    //int* res2 = (int*)malloc(sizeof(int) * (strLen1));
    convertStrToArray(version2, res2, &num2);

    print(res1, num1);
    print(res2, num2);
    int i = 0; 
    while (i < num1 && i < num2) {
        if (res1[i] < res2[i]) {
            return -1;
        }
        
        if (res1[i] > res2[i]) {
            return 1;
        }
        i++;
    }

    while (i < num1) {
        if (res1[i] != 0) {
            return 1;
        }
        i++;
    }
    while (i < num2) {
        if (res2[i] != 0) {
            return -1;
        }
        i++;
    }
    
    return 0;
}

void test01()
{
    char version1[] = "1.01";
    char version2[] = "1.001";
    int res = compareVersion(version1, version2);
    assert(res == 0);
}

void test02()
{
    char version1[] = "1.0";
    char version2[] = "1.0.0";
    int res = compareVersion(version1, version2);
    assert(res == 0);
}

void test03()
{
    char version1[] = "0.1";
    char version2[] = "1.1";
    int res = compareVersion(version1, version2);
    assert(res == -1);
}

void test04()
{
    char version1[] = "1.01";
    char version2[] = "1";
    int res = compareVersion(version1, version2);
    assert(res == 1);
}
void test05()
{
    char version1[] = "7.5.2.4";
    char version2[] = "7.5.3";
    int res = compareVersion(version1, version2);
    assert(res == -1);
}


int main()
{
#if 0
    test01();
#endif
    test02();
    test03();
#if 1
    test04();
    test05();
#endif

    return 0;
}

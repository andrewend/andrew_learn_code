#include <stdio.h>
#include <string.h>


void test01()
{
    char str[] = "hello@boy@this@is@heima";
    char* tmp = strtok(str, "@");

    printf("\n");
    while (tmp) {
        printf("[%s]\t", tmp);
        tmp = strtok(NULL, "@");
    }
}

void test02()
{
    char str[] = "/usr1/./yangbin/test/../netbios/bios/";
    char* tmp = strtok(str, "/");

    printf("\n");
    while (tmp) {
        printf("[%s]\t", tmp);
        tmp = strtok(NULL, "/");
    }
    printf("\n");
}
int main()
{
    test01();
    test02();

    return 0;
}

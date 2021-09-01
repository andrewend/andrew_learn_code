#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person{
    char* name;
    int height;
    int age;
    int grade;
} Person;

int cmp(const void* a, const void* b)
{
    Person * left = (Person*) a;
    Person * right = (Person*)b;
    return left->height - right->height;
}

void construct(Person* per, char* name, int height, int age, int grade) {
    per->name = (char*)malloc((strlen(name)+1) * sizeof(char));
    strcpy(per->name, name);
    per->height = height;
    per->age = age;
    per->grade = grade;
}

void print(Person per[], int perNum)
{
    printf("%s, %d\n", __func__, __LINE__);
    for (int i = 0; i < perNum; i++) {
        printf("name:%s, \theight:%d, tage:%d, \tgrade:%d \n", per[i].name, per[i].height, per[i].age, per[i].grade);
    }
}

void test01()
{
    Person per[8];
    construct(&per[0], "lingqi",  183, 4, 110);
    construct(&per[1], "yangbin",  173, 30, 100);
    construct(&per[2], "yangbin1", 104, 31, 130);
    construct(&per[3], "yangbin2", 175, 32, 100);
    construct(&per[4], "yangbin3", 176, 37, 190);
    construct(&per[5], "yangbin4", 197, 36, 180);
    construct(&per[6], "yangbin5", 178, 35, 150);
    construct(&per[7], "yangbin6", 179, 34, 130);

    printf("hello\n");
    int perArr = sizeof(per) / sizeof(per[0]);
    printf("perArr= %d\n", perArr);
    print(per, perArr);
    qsort(per, perArr, sizeof(per[0]), cmp);
    print(per, perArr);
}

int main()
{
    test01();

    return 0;
}

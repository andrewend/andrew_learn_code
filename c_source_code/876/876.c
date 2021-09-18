#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


struct ListNode {
    int val;
    struct ListNode *next;
};



struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *p = head;
    int i = 0;
    while (p != NULL) {
        p = p->next;
        i++;
    }
    printf("middleNode:%d\n", i);

    p = head;
    for (int j = 0; j < i / 2 && p != NULL; j++) {
        p = p->next;
    }
    return p;
}

struct ListNode* createList(int nums[], int numsSize)
{
    struct ListNode* head;
    struct ListNode* q;
    for (int i = 0; i < numsSize; i++) {
        struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->val = nums[i];
        p->next = NULL;
        if (i == 0) {
            head = p;
            q = p;
            continue;
        }

        q->next = p;
        q = q->next;
    }
    return head;
}

void print(struct ListNode * list)
{
    printf("list:=============\n");
    struct ListNode* p = list;
    while (p != NULL) {
        printf("%d\n", p->val);
        p = p->next;
    };
    printf("list:=============\n");
}

void test01()
{
    int nums[] = { 1, 2, 3, 4, 5};
    int arraySize = sizeof(nums) / sizeof(nums[0]);
    struct ListNode* list = createList(nums, arraySize);
    print(list);
    int numsExpect[] = { 3, 4, 5 };
    int numsSize = sizeof(numsExpect) / sizeof(numsExpect[0]);
    struct ListNode* expectList = createList(numsExpect, numsSize);
    print(expectList);
    struct ListNode* resList = middleNode(list);
    print(resList);

}

void test02()
{
    int nums[] = { 1, 2, 3, 4, 5, 6};
    int arraySize = sizeof(nums) / sizeof(nums[0]);
    struct ListNode* list = createList(nums, arraySize);
    print(list);
    int numsExpect[] = { 4, 5, 6 };
    int numsSize = sizeof(numsExpect) / sizeof(numsExpect[0]);
    struct ListNode* expectList = createList(numsExpect, numsSize);
    print(expectList);
    struct ListNode* resList = middleNode(list);
    print(resList);

}
int main()
{
    test01();
    test02();
    return 0;
}

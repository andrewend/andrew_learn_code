#include "uthash.h"
#include <stdio.h>
#include <stdlib.h>

struct userExample{
    int id;
    int value;
    UT_hash_handle hh;
};

void test01()
{
    struct userExample* user;
    struct userExample* users;
    for (int i = 0; i < 10; i++) {
        user = (struct userExample*)malloc(sizeof(struct userExample));
        if (user == NULL) {
            printf("malloc failed.\n");
            return;
        }

        user->id = i;
        user->value = i * i;
        HASH_ADD_INT(users, id, user);
    }

#if 1
    struct userExample* s;
    int key = 8;
    HASH_FIND_INT(users, &key, s);
    if (s == NULL) {
        printf("not find\n");
        return ;
    }
    printf("find key 8:id:%d, value:%d\n", s->id, s->value);

    struct userExample* tmp;
    HASH_ITER(hh, users, s, tmp) {
        printf("id:%d, value:%d\n", s->id, s->value);
        HASH_DEL(users, s);
        free(s);
    }
#else
    for (struct userExample* usr = users; usr != NULL; usr = (struct userExample*)usr->hh.next) {
        printf("id:%d, value:%d\n", usr->id, usr->value);
    }
#endif
    return;
}

int main()
{
    test01();

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <
int lengthOfLastWord(char * s){
    int n = strlen(s);
    int count = 0;
    while (s[n-1] == ' ' && n > 0) {
        n--;
    }
    while(s[n-1] != ' ' && n > 0) {
        count++;
        n--;
    }
    return count;
}

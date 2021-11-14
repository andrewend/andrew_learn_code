char* removeKdigits(char* num, int k) {
    int strLen = strlen(num);
    char* stack = malloc(strLen + 1); 
    int top = 0;
        
    for (int i = 0; i < strLen; i++) {
        while (top > 0 && stack[top-1] > num[i] && k) {
            top--;
            k--;
        }   
        stack[top++] = num[i];
    }                                                                                                  
    top -= k;
        
    char* ans = malloc(strLen + 1); 
    int size = 0;
    bool isLeaderZero = true;
        
    for (int i = 0; i < top; i++) {
        if (isLeaderZero && stack[i] == '0') {
            continue;
        }   
        isLeaderZero = false;
        ans[size++] = stack[i];
    }   
    if (size == 0) {
        return "0";
    } else {
        ans[size] = '\0';
    }   
        
    return ans;
} 

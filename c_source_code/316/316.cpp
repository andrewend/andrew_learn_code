string removeDuplicateLetters(string s) {
    int count[26] = { 0 };
    int isVisit[26] = { 0 };
    for (int i = 0; i < s.size(); i++) {
        count[s[i] - 'a']++;
    }

    string res = "";
    for (char ch : s) {
        if (isVisit[ch - 'a'] > 0) {
            ;
        } else {
            while (res.size() > 0 && res.back() > ch && count[res.back() - 'a'] > 0) {
                isVisit[res.back() - 'a'] = 0;
                res.popback();
            }
            res.push_back(ch);
            isVisit[ch - 'a'] = 1;
        }
        count[ch - 'a']--;
    }
    returnm res;
}

char * removeDuplicateLetters(char * s){
    int count[26] = { 0 };
    int isVisit[26] = { 0 };
    int strLen = strlen(s);
    for (int i = 0; i < strLen; i++) {
        count[s[i] - 'a']++;
    }

    char* res = malloc(strLen + 1);
    int k = 0;
    for (int i = 0; i < strLen; i++) {
        if (isVisit[s[i] - 'a'] > 0) {
            /* nothing*/;
        } else {
            while(k > 0 && res[k-1] > s[i] && count[res[k-1]-'a'] > 0) {
                isVisit[res[k-1]-'a'] = 0;
                k--;
            }
            res[k++] = s[i];
            isVisit[s[i] -'a'] = 1;
        }
        count[s[i]-'a']--;
    }
    return res;
}

char * predictPartyVictory(char * senate){
    bool R = true;
    int D = true;
    int strLen = strlen(senate);

    int flag = 0;
    while (R && D) {
        R = false;
        D = false;
        for (int i = 0; i < strLen; i++) {
            if (senate[i] == 'R') {
                if (flag < 0) {
                    senate[i] = 0;
                } else {
                    R = true;
                }
                flag++;
            }
            if (senate[i] == 'D') {
                if (flag > 0) {
                    senate[i] = 0;
                } else {
                    D = true;
                }
                flag--;
            }
        }
    }

    return R == true ? "Radiant" : "Dire";
}

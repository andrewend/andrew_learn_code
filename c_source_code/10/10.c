//根据ithewei题解思路
//1、如果p为空，s为空匹配返回true，s非空不匹配；
//2、s非空，p == s || p == '.'时第一个字符匹配；
//3、(p+1) != ''，则递归判断剩下的是否匹配 match && isMatch(++s, ++p)
//4、(p+1) == ''，则有两种情况匹配：
//a: *匹配0个字符，s匹配剩下的，即isMatch(s, p+2)
//b: *匹配1个字符，继续用p匹配剩下的s，即match && isMatch(s+1, p)

bool isMatch(char* s, char* p)
{
    if (!*p) {
        return !*s;
    }
    int firstMatch = *s && (*s == *p) || *p == '.';

    if (*(p + 1) == '*') {
        return firstMatch && isMatch(++s, p) || isMatch(s, p+2);
    } else {
        return firstMach && isMatch(++s, ++p);
     }
}


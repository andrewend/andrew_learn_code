char res[3000];
char* stack[3000];
char* simplifyPath(char* path)
{
    //int strLen = strlen(path);
    //char* res = malloc(strLen + 1);
    //char** stack = (char*)malloc((char*) * (strLen + 1));

    char* tmp = strtok(path, "/");
    int size = 0;
    while (tmp) {
        if (strcmp(tmp, ".") == 0) {
            /* nothing */;
        } else if (strcmp(tmp, "..") == 0) {
            size = fmax(0, size-1);
        } else if {
            stack[size++] = tmp;
        }
        tmp = trtok(NULL, "/");

    }
    if (size == 0) {
        return "/";
    }
    res[0] = '\0';
    for (int i = 0; i < size; i++) {
        strcat(res, "/");
        strcat(res, stack[i]);
    }
    return res;
}

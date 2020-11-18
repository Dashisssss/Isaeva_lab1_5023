#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char* mystrchr(const char* s, int c);

char* mystrtok(char* str, const char* d);

int main() {
    char s[100], * t, * word = NULL, d[] = " .,\!:t\n";
    int m = -1;

    printf("enter the string: ");
    fgets(s, 100, stdin);

    t = mystrtok(s, d);
    while (t != NULL) {
        int v = 0;
        char* p = t;
        while (*p != '\0')

            if (mystrchr("eyuaoi", *p++) != NULL)
                ++v;

        if (v > m) {
            word = t;
            m = v;
        }
        t = mystrtok(NULL, d);
    }
    if (word != NULL) printf("result: %s\n", word);
    return 0;
}
char* mystrchr(const char* s, int c) {
    while (*s != (char)c) {
        if (!*s++) {
            return NULL;
        }
    }
    return (char*)s;
}
char* mystrtok(char* str, const char* d) {
    static char* next;

    if (str) {
        next = str;
        while (*next && mystrchr(d, *next))
            *next++ = '\0';
    }
    if (!*next)
        return NULL;

    str = next;

    while (*next && !mystrchr(d, *next))
        ++next;
    while (*next && mystrchr(d, *next))
        *next++ = '\0';

    return str;
}
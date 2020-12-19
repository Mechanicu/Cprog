#include <stdio.h>

char* skip_space(char* s)
{
    while (*s == ' ') ++s;
    return s;
}

char* skip_word(char* s)
{
    while (*s != ' ' && *s != '\0') ++s;
    return s;
}

int main()
{
    char str[128];
    char *p = str;
    int cnt = 0;

    fgets(p, 127, stdin);

    while (1)
    {
        p = skip_space(p);
        if (*p == '\0') break;

        ++cnt;
        *p -= 32;
        p = skip_word(p);
    }

    printf("%s\n%d words\n", str, cnt);

    return 0;
}
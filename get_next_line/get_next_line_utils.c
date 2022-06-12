#include "get_next_line.h"

int ft_getstrlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char *ft_getstrdup(char *s)
{
    int i;
    char *p;
    int len;

    i = 0;
    len = ft_getstrlen(s);
    p = malloc(len + 1);
    if (!p)
        return (NULL);
    while (i < len)
    {
        p[i] = s[i];
        i++;
    }
    p[i] = '\0';
    return (p);
}

char *substr(char *s, int start, int len)
{
    char *p;
    int size;
    int i;

    size = 0;
    i = start;
    if (start >= ft_getstrlen(s))
        return (ft_getstrdup(""));
    while (size < len && s[i] != '\0')
    {
        size++;
        i++;
    }
    p = malloc(sizeof(char) * size + 1);
    if (!p)
        return (NULL);
    i = 0;
    while(i < size)
    {
        p[i++] = s[start++];
    }
    p[i] = '\0';
    return (p);
}
char *after_nline(char *s, int start)
{
    char *new;

    new = ft_getstrdup(s + start);
    free(s);
    return (new);
}

char *join(char *s1, char *s2)
{
    char *p;
    int size;
    int i;
    int j;

    j = 0;
    i = 0;
    if (!s1)
        return (ft_getstrdup(s2));
    size = ft_getstrlen(s1) + ft_getstrlen(s2);
    p = malloc(size + 1);
    if (!p)
        return (NULL);
    while (s1[i])
    {
        p[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        p[i++] = s2[j++];
    }
    p[i] = '\0';
    free(s1);
    return (p);
}
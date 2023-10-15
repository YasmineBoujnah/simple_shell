#include "shell.h"

/**
 * @s: takes first string
 * @s1: takes second string
 *
 * Return: first string
 */

char *_strcpy(char *s, char *s1)
{
    int i = 0;

    if (s == s1 || s1 == 0)
        return (s);
    while (s1[i])
    {
        s[i] = s1[i];
        i++;
    }
    s[i] = 0;
    return (s);
}

/**
 * @s: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *s)
{
    int length = 0;
    char *ret;

    if (s == NULL)
        return (NULL);
    while (*s++)
        length++;
    ret = malloc(sizeof(char) * (length + 1));
    if (!ret)
        return (NULL);
    for (length++; length--;)
        ret[length] = *--s;
    return (ret);
}

/**
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
    int i = 0;

    if (!str)
        return;
    while (str[i] != '\0')
    {
        _putchar(str[i]);
        i++;
    }
}

/**
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    static int i;
    static char buf[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(1, buf, i);
        i = 0;
    }
    if (c != BUF_FLUSH)
        buf[i++] = c;
    return (1);
}

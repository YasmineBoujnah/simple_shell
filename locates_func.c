#include "shell.h"

/**
 * @s: pointer to the string content the character 'c' to search
 * @c: character you want to search for in the string 's'
 * Return: pointer to the first occurence of 'c' in the string
 * or NULL if 's' isn't found
 */

char *_strchr(char *s, char c)

{
    do {
        if (*s == c)
            return (s);
    } while (*s++ != '\0');

    return (NULL);
}

/**
 * @dest: A pointer to the buffer where the copied string will be stored.
 * @src: A pointer to the source string that you want to copy.
 * @n: number of characters to be copied from the src.
 * Return: A pointer to the distination buffer dest
 */

char *_strncpy(char *dest, char *src, int n)

{
    int i, j;
    char *s = dest;

    i = 0;
    while (src[i] != '\0' && i < n - 1)
    {
        dest[i] = src[i];
        i++;
    }
    if (i < n)
    {
        j = i;
        while (j < n)
        {
            dest[j] = '\0';
            j++;
        }
    }
    return (s);
}

/**
 * @dest: pointer to the string to which the char willbe appended
 * @src:pointer to the string from char will be concatenated
 * @n: numbers of char to concatenate from src
 * Return: pointer to dest
 */

char *_strncat(char *dest, char *src, int n)

{
    int i, j;
    char *s = dest;

    i = 0;
    j = 0;
    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0' && j < n)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    if (j < n)
        dest[i] = '\0';
    return (s);
}

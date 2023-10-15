#include "shell.h"

/**
 * @str: the string to use.
 *
 * Return: integer
 */

int _atoi(char *str)
{
    int i, sign = 1, flag = 0, output;
    unsigned int result = 0;

    for (i = 0;  str[i] != '\0' && flag != 2; i++)
    {
        if (str[i] == '-')
            sign *= -1;

        if (str[i] >= '0' && str[i] <= '9')
        {
            flag = 1;
            result *= 10;
            result += (str[i] - '0');
        }
        else if (flag == 1)
            flag = 2;
    }

    if (sign == -1)
        output = -result;
    else
        output = result;

    return (output);
}

/**
 * @info: struct address
 * Return: 1 for interactive mode, otherwise 0
 */

int inter_active(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * @ch: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int is_alpha(int ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return (1);
    else
        return (0);
}

/**
 * @ch: the character to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */

int is_a_delim(char ch, char *delim)
{
    while (*delim)
        if (*delim++ == ch)
            return (1);
    return (0);
}


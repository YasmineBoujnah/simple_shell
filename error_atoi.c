#include "shell.h"

/**
 * @info: the parameter & return info struct
 * @erstr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_Error(info_t *info, char *erstr)
{
    eput_str(info->fname);
    eput_str(": ");
    print_dec(info->line_count, STDERR_FILENO);
    eput_str(": ");
    eput_str(info->argv[0]);
    eput_str(": ");
    eput_str(erstr);
}

/**
 * @buffer: address of the string to modify
 *
 * Return: Always 0;
 */
void delete_comments(char *buffer)
{
    int i;

    for (i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '#' && (!i || buffer[i - 1] == ' '))
        {
            buffer[i] = '\0';
            break;
        }
}

/**
 * @num: inputed number
 * @base: a base
 * @flags: arguments
 *
 * Return: a string
 */
char *change_num(long int num, int base, int flags)
{
    static char *array;
    static char buffer[50];
    char sign = 0;
    char *ptr;
    unsigned long n = num;

    if (!(flags & CONVERT_UNSIGNED) && num < 0)
    {
        n = -num;
        sign = '-';

    }
    array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
    ptr = &buffer[49];
    *ptr = '\0';

    do  {
        *--ptr = array[n % base];
        n /= base;
    } while (n != 0);

    if (sign)
        *--ptr = sign;
    return (ptr);
}

/**
 * @input: the input
 * @fdis: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_dec(int input, int fdis)
{
    int (*__putchar)(char) = _putchar;
    int i, count = 0;
    unsigned int _abs_, current;

    if (fdis == STDERR_FILENO)
        __putchar = _eput_char;
    if (input < 0)
    {
        _abs_ = -input;
        __putchar('-');
        count++;
    }
    else
        _abs_ = input;
    current = _abs_;
    for (i = 1000000000; i > 1; i /= 10)
    {
        if (_abs_ / i)
        {
            __putchar('0' + current / i);
            count++;
        }
        current %= i;
    }
    __putchar('0' + current);
    count++;

    return (count);
}

/**
 * @str: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int err_atoi(char *str)
{
    int i = 0;
    unsigned long int result = 0;

    if (*str == '+')
        str++;
    for (i = 0;  str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            result *= 10;
            result += (str[i] - '0');
            if (result > INT_MAX)
                return (-1);
        }
        else
            return (-1);
    }
    return (result);
}


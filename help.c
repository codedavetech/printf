#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * print_repeat - Prints a character n times
 * @c: The character to print
 * @n: The number of times to print the character.
 * @n: The number of times to print the character.
 */
void print_repeat(char c, int n)
{
	int z;

	for (z = 0; z < n; z++)
		_putchar(c);
}

/**
 * _putnchars - Prints multiple characters
 * @n: The number of characters to print
 */
void _putnchars(int n, ...)
{
	int z;
	va_list args;

	if (n <= 0)
		return;
	va_start(args, n);
	for (z = 0; z < n; z++)
	{
		_putchar(va_arg(args, int));
	}
	va_end(args);
}

/**
 * is_letter - Checks if the given character is a letter
 * @c: The character to check
 *
 * Return: 1 or 0
 */
char is_letter(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ? TRUE : FALSE);
}

/**
 * set_format_error - Sets the error after reading a format specifier
 * @format: The format string
 * @pos: The current position in the format string
 * @len: The length of the format specifier minus 1
 * @last_token: The last token from the format specifier
 * @error: The format error flag
 */
void set_format_error(const char *format, int *pos, int len,
	int last_token, int *error)
{
	char next_char = format[*pos + len + 1];
	int z;

	if (last_token == 1 && next_char == '\0')
	{
		*error = -1;
	}
	else if ((last_token == 2 || last_token == 3) && next_char == '\0')
	{
		*error = -1;
		(*pos) += len - 1;
	}
	else if (last_token == 4 && next_char == '\0')
	{
		*error = -1;
	}
	else
	{
		*error = 1;
	}
	if (next_char != '\0' && last_token != 5)
	{
		_putchar('%');
		for (z = 0; z <= len; z++)
		{
			if (!is_length(format[*pos + z]))
				_putchar(format[*pos + z]);
		}
		(*pos) += len;
	}
}

/**
 * put_num - Prints a number to the buffer
 * @zeros_count: The number of zeros to print
 * @num: The number
 * @str: The string representation of the number
 */
void put_num(int zeros_count, long num, char *str)
{
	int z;

	for (z = 0; z < zeros_count; z++)
		_putchar('0');
	for (z = num < 0 ? 1 : 0; *(str + z) != '\0'; z++)
		_putchar(*(str + z));
}

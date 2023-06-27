#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - prints output in format
 * @format:  specified format.
 *
 * Return: Number of characters that was printed
 */
 
int _printf(const char *format, ...)
{
	int a = 0, tmp, processing_escape = FALSE, error = 1, last_token;
	fmt_info_t fmt_info;
	va_list args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	write_to_buffer(0, -1);
	for (a = 0; format && *(format + a) != '\0'; a++)
	{
		if (processing_escape)
		{
			tmp = read_format_info(format + a, args, &fmt_info, &last_token);
			processing_escape = FALSE;
			set_format_error(format, &a, tmp, last_token, &error);
			if (is_specifier(fmt_info.spec))
				write_format(&args, &fmt_info);
			a += (is_specifier(fmt_info.spec) ? tmp : 0);
		}
		else
		{
			if (*(format + a) == '%')
				processing_escape = TRUE;
			else
				_putchar(*(format + a));
		}
	}
	write_to_buffer(0, 1);
	va_end(args);
	return (error <= 0 ? error : write_to_buffer('\0', -2));
}

/**
 * write_format - Writes data formatted against some parameters
 * @args_list: The arguments list
 * @fmt_info: The format info parameters that were read
 */
void write_format(va_list *args_list, fmt_info_t *fmt_info)
{
	int a;
	spec_printer_t spec_printers[] = {
		{'%', convert_fmt_percent},
		{'p', convert_fmt_p},
		{'c', convert_fmt_c},
		{'s', convert_fmt_s},
		{'d', convert_fmt_di},
		{'i', convert_fmt_di},
		{'X', convert_fmt_xX},
		{'x', convert_fmt_xX},
		{'o', convert_fmt_o},
		{'u', convert_fmt_u},
		/* #begin custom specifiers */
		{'b', convert_fmt_b},
		{'R', convert_fmt_R},
		{'r', convert_fmt_r},
		{'S', convert_fmt_S},
		/* #end */
		{'F', convert_fmt_fF},
		{'f', convert_fmt_fF},
	};

	for (a = 0; a < 23 && spec_printers[a].spec != '\0'; a++)
	{
		if (fmt_info->spec == spec_printers[a].spec)
		{
			spec_printers[a].print_arg(args_list, fmt_info);
			break;
		}
	}
}

/**
 * _putstr - writes the given string to the buffer
 * @str: The string to write
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putstr(char *str)
{
	int a, out;

	for (a = 0; str && *(str + a) != 0; a++)
		out = _putchar(*(str + a));
	return (out);
}

/**
 * _putchar - writes the character c to the buffer
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write_to_buffer(c, 0));
}

/**
 * write_to_buffer - Writes a char to the buffer based on an action code
 * @c: The character to write
 * @action: The action to perform (
 * -1-> reset the static variables
 * 0-> write char to buffer
 * 1-> don't write character to buffer but empty buffer onto stdout
 * -2-> the number of characters written to stdout)
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int write_to_buffer(char c, char action)
{
	static int a;
	static int chars_count;
	static char buffer[1024];
	static char out;

	if (a < 1024 && action == 0)
	{
		out = chars_count < 1 ? 1 : out;
		buffer[a] = c;
		a++;
		chars_count++;
	}
	if (a >= 1024 || action == 1)
	{
		out = write(1, buffer, a);
		fflush(stdout);
		a = 0;
		mem_set(buffer, 1024, 0);
	}
	if (action == -1)
	{
		a = 0;
		chars_count = 0;
		mem_set(buffer, 1024, 0);
	}
	if (action == -2)
	{
		return (chars_count);
	}
	return (out);
}

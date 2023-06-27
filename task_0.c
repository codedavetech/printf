#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * convert_fmt_percent - Prints a percent sign (%)
 * @args_list: The arguments list.
 * @args_list: The arguments list.
 * @fmt_info: The format info
 */
void convert_fmt_percent(va_list *args_list, fmt_info_t *fmt_info)
{
	(void)args_list;
	_putchar(fmt_info->spec);
}

/**
 * convert_fmt_p - Prints the pointer address
 * @args_list: The arguments list
 * @fmt_info: The format info
 */
void convert_fmt_p(va_list *args_list, fmt_info_t *fmt_info)
{
	int z, len;
	void *ptr = va_arg(*args_list, void *);
	char *str = ptr_to_str(ptr);

	(void)fmt_info;
	if (str)
	{
		len = str_len(str);
		if (!fmt_info->left)
		{
			for (z = 0; z < MAX(len, fmt_info->width) - len; z++)
				_putchar(' ');
		}
		for (z = 0; *(str + z) != '\0'; z++)
			_putchar(*(str + z));
		if (fmt_info->left)
		{
			for (z = 0; z < MAX(len, fmt_info->width) - len; z++)
				_putchar(' ');
		}
		free(str);
	}
	else
	{
		_putstr("(nil)");
		if (str)
			free(str);
	}
}

/**
 * convert_fmt_c - Prints a character
 * @args_list: The arguments list
 * @fmt_info: The format info
 */
void convert_fmt_c(va_list *args_list, fmt_info_t *fmt_info)
{
	int z, len = 1;
	char str = va_arg(*args_list, int);

	if (!fmt_info->left)
	{
		for (z = 0; z < MAX(len, fmt_info->width) - len; z++)
			_putchar(' ');
	}
	_putchar(str);
	if (fmt_info->left)
	{
		for (z = 0; z < MAX(len, fmt_info->width) - len; z++)
			_putchar(' ');
	}
}

/**
 * convert_fmt_s - Prints a string
 * @args_list: The arguments list
 * @fmt_info: The format info
 */
void convert_fmt_s(va_list *args_list, fmt_info_t *fmt_info)
{
	int z, len;
	char *str = va_arg(*args_list, char *);
	char null_str[] = "(null)";

	str = str ? str : null_str;
	len = fmt_info->is_precision_set && fmt_info->prec >= 0
		? fmt_info->prec : str_len(str);
	if (!fmt_info->left)
	{
		for (z = 0; z < MAX(len, fmt_info->width) - len; i++)
			_putchar(' ');
	}
	for (z = 0; z < len && *(str + z) != '\0'; z++)
		_putchar(*(str + z));
	if (fmt_info->left)
	{
		for (z = 0; z < MAX(len, fmt_info->width) - len; z++)
			_putchar(' ');
	}
}



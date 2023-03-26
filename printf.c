#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * _printf - produces output according to format
 * @format: an input
 * Return: number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list ap;
	char buff[100] = {0}, *s;
	int j = 0, i = 0;

	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				buff[j] = (char) va_arg(ap, int);
				j++;
			}
			else if (format[i] == 's')
			{
				s = va_arg(ap, char *);
				strcpy(&buff[j], s);
				j += strlen(s);
			}
			else if (format[i] == '%')
			{
				buff[j] = '%';
				j++;
			}
		}
		else
		{
			buff[j] = format[i];
			j++;
		}
		i++;
	}
	fwrite(buff, j, 1, stdout);
	va_end(ap);
	return (j);
}

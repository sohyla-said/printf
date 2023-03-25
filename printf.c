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
	char c, *s;
	int printed = 0;
	unsigned int i;

	va_start(ap, format);
	while (format == NULL)
		return (-1);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = (char) va_arg(ap, int);
				putchar(c);
				printed++;
			}
			else if (*format == 's')
			{
				s = va_arg(ap, char*);
				for (i = 0; i < strlen(s); i++)
					putchar(s[i]);
				printed += strlen(s);
			}
			else if (*format == '%')
			{
				putchar('%');
				printed++;
			}
		}
		else
		{
			putchar(*format);
			printed++;
		}
		format++;
	}
	putchar('\n');
	va_end(ap);
	return (printed);
}

#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * print_string - prints a string
 * @s: an input
 * Return: nothinh
 */
void print_string(char *s)
{
	unsigned int i;

	for (i = 0; i < strlen(s); i++)
	{
		putchar(s[i]);
	}
}
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

	va_start(ap, format);
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
				print_string(s);
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
	va_end(ap);
	return (printed);
}

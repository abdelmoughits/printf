#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
void ttc(int num);
/**
  *_printf - a simple version of printf
  *@format: a pointer to a const char
  *@...: the other parameters
  *Return: the number of charactes printed
  */
int _printf(const char *format, ...)
{
	va_list ap;
	char *ss;
	int i, b, dec, value, result = 0;

	i = 0;
	va_start(ap, format);
	while (format && format[i])
	{
		b = 0;
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case '%':
					write(1, "%", 1);
					b++;
					i++;
					break;
				case 'c':
					value  = va_arg(ap, int);
					write(1, &value, 1);
					b++;
					i++;
					break;
				case 's':
					ss = va_arg(ap, char *);
					b = strlen(ss);
					write(1, ss, b);
					i++;
					break;
				case 'i':
				case 'd':
					dec = va_arg(ap, int);
					if (dec < 0)
					{
						write(1, "-", 1);
						dec *= -1;
					}
					ttc(dec);
					i++;
					b++;
					break;
				default:
					write(1, &(format[i]), 1);
					b++;
			}
		}
		else
		{
			write(1, &(format[i]), 1);
			b++;
		}
		result += b;
		i++;
	}
	va_end(ap);
	return (result);
}
/**
  *ttc - print a number with write
  *@num: the number that will be treated
  *Return: times where the write used
  */
void ttc(int num)
{
	char ptr;
	int b = 0;

	if ((num / 10) != 0)
	{
		b = num / 10;
		ttc(b);
	}
	ptr = (num % 10) + '0';
	write(1, &ptr, 1);
}

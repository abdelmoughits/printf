#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
int ttc(unsigned int num);
int octa(unsigned int num);
int exa(unsigned int num, int lar);
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
	int i, b, t, value, result = 0;
	unsigned int dec;

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
				case 'o':
					t = va_arg(ap, int);
					dec = (unsigned int)t;
					b = octa(dec);
					i++;
					break;
				case 'u':
					dec = va_arg(ap, int);
					b = ttc(dec);
					i++;
					break;
				case 'x':
					t = va_arg(ap, int);
					dec = (unsigned int)t;
					b = exa(dec, 97);
					i++;
					break;
				case 'X':
					t = va_arg(ap, int);
					dec = (unsigned int)t;
					b = exa(dec, 65);
					i++;
					break;
				case 'i':
				case 'd':
					t = va_arg(ap, int);
					dec = (unsigned int)t;
					if (t < 0)
					{
						write(1, "-", 1);
						t *= -1;
						b++;
					}
					b += ttc(t);
					i++;
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
  *Return: nothing
  */
int ttc(unsigned int num)
{
	char ptr;
	int b = 0, c = 1;

	if ((num / 10) != 0)
	{
		b = num / 10;
		c += ttc(b);
	}
	ptr = (num % 10) + '0';
	write(1, &ptr, 1);
	return (c);
}
/**
  *octa - print a number with write
  *@num: the number that will be treated
  *Return: nothing
  */
int octa(unsigned int num)
{
	char ptr;
	int b = 0, c = 1;

	if ((num / 8) != 0)
	{
		b = num / 8;
		c += octa(b);
	}
	ptr = (num % 8) + '0';
	write(1, &ptr, 1);
	return (c);
}
/**
  *exa - print a number with write
  *@num: the number that will be treated
  *Return: nothing
  */
int exa(unsigned int num, int lar)
{
	char ptr;
	int b = 0, c = 1;

	if ((num / 16) != 0)
	{
		b = num / 16;
		c += exa(b, lar);
	}
	if (num % 16 <= 9)
	{
		ptr = (num % 16) + '0';
	}
	else
	{
		ptr = (num % 16) - 10 + lar;
	}
	write(1, &ptr, 1);
	return (c);
}

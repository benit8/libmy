/*
** printf.c for libmy in /mnt/data/Delivery/Perso/libmy/Tests
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Nov 8 10:00:35 2017 Benoit Lormeau
** Last update Tue Nov 14 10:24:01 2017 Benoit Lormeau
*/

#include <limits.h>
#include <stdio.h>
#include "my.h"

void test(const char *format, ...)
{
	va_list ap, ap2;
	int a, b;

	va_start(ap, format);
	va_copy(ap2, ap);

	a =    vprintf(format, ap);
	b = my_vprintf(format, ap2);

	va_end(ap);
	va_end(ap2);

	printf("%d | %d\n\n", a, b);
}


int main(void)
{
	// test("Hello World!|\n");
	// test("Hello %.4s %%|\n", "World");
	// test("[%4y]|\n"); // Non-existing specifier
	// test("[%+x] [%+x]|\n", -12, 12);

	test("LLONG_MAX [%%b] %b|\n", INT_MIN);
	test("LLONG_MAX [%%llo] %llo|\n", LLONG_MIN);
	test("LLONG_MIN [%%lX] %lX|\n", 7155555542);
	test("ULLONG_MAX [%%llu] %llu|\n", ULLONG_MAX);

	test("%f\n", 1.175494);


	return (0);
}
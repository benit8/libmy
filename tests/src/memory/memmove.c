/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** memmove.c
*/

#include <criterion/criterion.h>
#include "my/memory.h"

Test(Memory, memmove)
{
	cr_expect_null(my_memmove(NULL, NULL, 0));
	cr_expect_null(my_memmove(NULL, NULL, 1));
	cr_expect_null(my_memmove("NULL", NULL, 0));
	cr_expect_null(my_memmove("NULL", NULL, 1));
	cr_expect_null(my_memmove(NULL, "NULL", 0));
	cr_expect_null(my_memmove(NULL, "NULL", 1));
	cr_expect_null(my_memmove("NULL", "NULL", 0));


	char a[12]; my_memcpy(a, "Hello World!", 12);
	char b[12];
	cr_expect_eq(my_memmove(b, a, 12), &b[0]);
	cr_expect_eq(my_memcmp(b, "Hello World!", 12), 0);


	char c[12]; my_memcpy(c, "Hello World!", 12);
	cr_expect_eq(my_memmove(c + 6, c, 5), &c[6]);
	cr_expect_eq(my_memcmp(c, "Hello Hello!", 12), 0);


	char d[12]; my_memcpy(d, "Hello World!", 12);
	cr_expect_eq(my_memmove(d, d + 4, 7), &d[0]);
	cr_expect_eq(my_memcmp(d, "o Worldorld!", 12), 0);
}
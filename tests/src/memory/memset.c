/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** memset.c
*/

#include <criterion/criterion.h>
#include "my/memory.h"

Test(Memory, memset)
{
	cr_expect_null(my_memset(NULL, 0, 0));
	cr_expect_null(my_memset(NULL, 0, 1));
	cr_expect_null(my_memset("NULL", 0, 0));

	char a[8];
	cr_expect_eq(my_memset(a, '0', 8), &a[0]);
	for (size_t i = 0; i < 8; ++i)
		cr_expect_eq(a[i], '0');
}
/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** memcpy.c
*/

#include <criterion/criterion.h>
#include "my/memory.h"

Test(Memory, memcpy)
{
	char buff[25];
	char *dest = &buff[0];

	cr_expect_null(my_memcpy(NULL, NULL, 0));
	cr_expect_null(my_memcpy(NULL, NULL, 1));
	cr_expect_eq(my_memcpy(dest, NULL, 0), dest);
	cr_expect_eq(my_memcpy(dest, NULL, 1), dest);

	cr_expect_eq(my_memcpy(dest, "Hello World", 0), dest);
	cr_expect_eq(my_memcpy(dest, "Hello World", 11), dest);
	cr_expect_eq(my_memcmp(dest, "Hello World", 11), 0);
}
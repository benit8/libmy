/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** memdup.c
*/

#include <criterion/criterion.h>
#include "my/memory.h"

Test(Memory, memdup)
{
	cr_expect_null(my_memdup(NULL, 0));
	cr_expect_null(my_memdup(NULL, 1));
	cr_expect_null(my_memdup("00", 0));

	char *ptr = my_memdup("00", 2);
	cr_expect_eq(my_memcmp(ptr, "00", 2), 0);
	my_free(ptr);
}
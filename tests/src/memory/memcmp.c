/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** memcmp.c
*/

#include <criterion/criterion.h>
#include "my/memory.h"
#include <string.h>

Test(Memory, memcmp)
{
	cr_expect_eq(my_memcmp(NULL, NULL, 0), 0);
	cr_expect_eq(my_memcmp(NULL, NULL, 4), 0);

	cr_expect_eq(my_memcmp(NULL, "", 0), 0);
	cr_expect_lt(my_memcmp(NULL, "", 1), 0);

	cr_expect_eq(my_memcmp("", NULL, 0), 0);
	cr_expect_gt(my_memcmp("", NULL, 1), 0);

	cr_expect_eq(my_memcmp("hello world", "helloWoRLD", 0), 0);
	cr_expect_eq(my_memcmp("hello world", "helloWoRLD", 5), 0);
	cr_expect_eq(my_memcmp("hello world", "helloWoRLD", 10), (' ' - 'W'));
}
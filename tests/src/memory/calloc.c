/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** calloc.c
*/

#include <criterion/criterion.h>
#include "my/memory.h"

Test(Memory, calloc)
{
	cr_assert_null(my_calloc(0, 0));
	cr_assert_null(my_calloc(0, 1));
	cr_assert_null(my_calloc(1, 0));


	size_t sample_size = 4;
	char *ptr = my_calloc(sample_size, sizeof(char));
	cr_assert_not_null(ptr);
	cr_assert_eq(my_malloc_size(ptr), sample_size);
	for (size_t i = 0; i < sample_size; ++i)
		cr_assert_eq(ptr[i], 0);
	my_free(ptr);
}
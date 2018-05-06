/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** realloc.c
*/

#include <criterion/criterion.h>
#include "my/memory.h"

Test(Memory, realloc)
{
	cr_expect_null(my_realloc(NULL, 0));


	size_t size = 4;
	char *a = my_calloc(size, sizeof(char));
	cr_assert_not_null(a);
	cr_assert_eq(my_malloc_size(a), size);

	// Inferior size to the original one
	// Should not realloc and return the original pointer
	char *b = my_realloc(a, size / 2);
	cr_assert_eq(a, b);

	char *c = my_realloc(a, size * 2);
	cr_assert_neq(a, c);
	cr_assert_eq(my_malloc_size(c), size * 2);
	my_free(c);
}
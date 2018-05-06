/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** malloc.c
*/

#include <criterion/criterion.h>
#include "my/memory.h"

Test(Memory, malloc)
{
	cr_assert_null(my_malloc(0));


	size_t sample_size = 4;
	void *ptr = my_malloc(sample_size);
	cr_assert_not_null(ptr);
	cr_assert_eq(my_malloc_size(ptr), sample_size);
	my_free(ptr);
}

Test(Memory, free)
{
	my_free(NULL);
}

Test(Memory, my_malloc_size)
{
	cr_assert_eq(my_malloc_size(NULL), 0);
}
/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** sort.c
*/

#include "my/dsa.h"

void swap(void *va, void *vb, size_t s)
{
	byte_t *a = (byte_t *)va;
	byte_t *b = (byte_t *)vb;
	byte_t t = 0;

	while (s--) {
		t = a[s];
		a[s] = b[s];
		b[s] = t;
	}
}

void sort(void *ptr, size_t n, size_t s, comp_func_t *cmp)
{
	byte_t pivot[s];
	byte_t *p = ptr;
	size_t i = 0;
	size_t j = 0;

	if (n < 2)
		return;
	mem_cpy(pivot, p + ((n / 2) * s), s);
	for (i = 0, j = n - 1; ; i++, j--) {
		for (; (*cmp)(p + (i * s), pivot) < 0; ++i);
		for (; (*cmp)(p + (j * s), pivot) > 0; --j);
		if (i >= j)
			break;
		swap(p + (i * s), p + (j * s), s);
	}
	sort(p, i, s, cmp);
	sort(p + (i * s), n - i, s, cmp);
}
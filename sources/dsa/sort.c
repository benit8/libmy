/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** sort.c
*/

#include "dsa.h"

void swap(void *va, void *vb, size_t s)
{
	char *a = (char*)va;
	char *b = (char*)vb;
	char t;

	while (s--) {
		t = a[s];
		a[s] = b[s];
		b[s] = t;
	}
}

void sort(void *ptr, size_t n, size_t s, cmp_func_t *cmp)
{
	char pivot[s];
	char *p = ptr;
	size_t i;
	size_t j;

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
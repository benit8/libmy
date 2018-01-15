/*
** memcmp.c for libmy in /mnt/data/Delivery/Perso/Libmy/sources/memory
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Dec 27 23:36:36 2017 Benoit Lormeau
** Last update Wed Dec 27 23:36:36 2017 Benoit Lormeau
*/

#include "memory.h"

int mem_cmp(const void *a, const void *b, size_t n)
{
	const char *sa = a;
	const char *sb = b;

	while (n--) {
		if (*sa++ != *sb++)
			return (*sa - *sb);
	}
	return (0);
}
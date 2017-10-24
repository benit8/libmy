/*
** strncmp.c for libmy in /mnt/data/Delivery/Perso/libmy/string
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 11:18:42 2017 Benoit Lormeau
** Last update Mon Oct 23 11:18:42 2017 Benoit Lormeau
*/

#include "libmy.h"

int my_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	for (; *s1 == *s2 && --n > 0; s1++, s2++);
	return (*s1 - *s2);
}
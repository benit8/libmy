/*
** memcpy.c for memcpy in /home/benito/Dropbox/Code
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Thu Sep 28 11:38:15 2017 Benoit Lormeau
** Last update Thu Sep 28 11:38:20 2017 Benoit Lormeau
*/

#include "libmy.h"

void *my_memcpy(void *dest, const void *src, size_t len)
{
	register uint8_t *d;
	register const uint8_t *s;

	d = dest;
	s = src;
	while (len--)
		*d++ = *s++;
	return dest;
}
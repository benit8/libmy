/*
** strncpy.c for libmy in /mnt/data/Delivery/Perso/libmy/string
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 10:41:04 2017 Benoit Lormeau
** Last update Mon Oct 23 10:41:04 2017 Benoit Lormeau
*/

#include "libmy.h"

char *my_strncpy(char *dest, const char *src, size_t n)
{
	char *s = dest;

	while (n > 0 && *src != '\0'){
		*s++ = *src++;
		--n;
	}
	while (n > 0){
		*s++ = '\0';
		--n;
	}
	return (dest);
}
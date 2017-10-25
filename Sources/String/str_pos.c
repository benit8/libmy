/*
** str_pos.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/String
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 22:53:41 2017 Benoit Lormeau
** Last update Wed Oct 25 22:53:41 2017 Benoit Lormeau
*/

#include "libmy.h"

size_t str_pos(char *string, const char *search)
{
	char *s = string;
	register char *a;
	register const char *b = search;

	if (str_empty(string) || str_empty(search))
		return ((size_t)(-1));
	for (; *s != '\0'; s++){
		if (*s != *b)
			continue;
		a = s;
		while (1){
			if (*b == '\0')
				return (s - string);
			if (*a++ != *b++)
				break;
		}
		b = search;
	}
	return ((size_t)(-1));
}
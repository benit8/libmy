/*
** strstr.c for libmy in /mnt/data/Delivery/Perso/libmy/string
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 14:17:38 2017 Benoit Lormeau
** Last update Mon Oct 23 14:17:38 2017 Benoit Lormeau
*/

#include "libmy.h"

char *my_strstr(char *string, const char *search)
{
	register char *a;
	register const char *b = search;

	if (*b == '\0')
		return (string);
	for (; *string != '\0'; string++){
		if (*string != *b)
			continue;
		a = string;
		while (1){
			if (*b == '\0')
				return string;
			if (*a++ != *b++)
				break;
		}
		b = search;
	}
	return (NULL);
}
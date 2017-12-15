/*
** str_tolower.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/String
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Sat Oct 28 15:02:21 2017 Benoit Lormeau
** Last update Sat Oct 28 15:02:21 2017 Benoit Lormeau
*/

#include "string.h"

char *str_tolower(char *str)
{
	register char *s = str;

	for (; *s != 0; ++s){
		if (is_upper(*s))
			*s += 32;
	}
	return (str);
}
/*
** str_toupper.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/String
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Sat Oct 28 15:04:59 2017 Benoit Lormeau
** Last update Sat Oct 28 15:04:59 2017 Benoit Lormeau
*/

#include "String.h"

char *str_toupper(char *str)
{
	register char *s = str;

	for (; *s != 0; ++s){
		if (is_lower(*s))
			*s -= 32;
	}
	return (str);
}
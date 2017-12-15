/*
** str_trim.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/String
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 11 13:55:23 2017 Benoit Lormeau
** Last update Mon Dec 11 13:55:23 2017 Benoit Lormeau
*/

#include "string.h"

char *str_trim(char *str)
{
	char *dest = str;
	char *end;

	end = str + str_len(str);
	for (; *str && is_space(*str); str++);
	while (end > str) {
		if (!is_space(*(end - 1)))
			break;
		end--;
	}
	*end = '\0';
	mem_move(dest, str, end - str + 1);
	return (dest);
}

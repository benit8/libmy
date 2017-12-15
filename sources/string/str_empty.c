/*
** str_empty.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/String
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 22:55:49 2017 Benoit Lormeau
** Last update Wed Oct 25 22:55:49 2017 Benoit Lormeau
*/

#include "string.h"

bool str_empty(const char *string)
{
	const char *s = string;

	if (s == NULL)
		return (true);
	for (; *s != '\0'; ++s){
		if (!is_blank(*s))
			return (false);
	}
	return (true);
}
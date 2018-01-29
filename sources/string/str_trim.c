/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** str_trim.c
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

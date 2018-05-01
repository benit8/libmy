/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_strtrim.c
*/

#include "my/string.h"

char *my_strtrim(char *str)
{
	char *dest = str;
	char *end = str + my_strlen(str);

	for (; *str && is_space(*str); str++);
	while (end > str) {
		if (!is_space(*(end - 1)))
			break;
		end--;
	}
	*end = '\0';
	my_memmove(dest, str, end - str + 1);
	return (dest);
}
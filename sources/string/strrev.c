/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strrev.c
*/

#include "my/string.h"

char *str_rev(char *str)
{
	size_t len = str_len(str);
	char t = 0;

	for (size_t i = 0; i < len / 2; ++i) {
		t = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = t;
	}
	return (str);
}
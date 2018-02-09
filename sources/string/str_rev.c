/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** str_rev.c
*/

#include "string.h"

char *str_rev(char *str)
{
	size_t l = str_len(str);
	char t = 0;

	for (size_t i = 0; i < l / 2; ++i){
		t = str[i];
		str[i] = str[l - i - 1];
		str[l - i - 1] = t;
	}
	return (str);
}
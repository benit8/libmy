/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strppd.c
*/

#include "my/string.h"

char *my_strppd(char *string, const char *span)
{
	size_t n = my_strlen(span);

	string = my_strrev(string);
	string = my_strnapd(string, span, n);
	return (my_strrev(string));
}

char *my_strnppd(char *string, const char *span, size_t n)
{
	string = my_strrev(string);
	string = my_strnapd(string, span, n);
	return (my_strrev(string));
}
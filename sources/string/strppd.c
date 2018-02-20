/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strppd.c
*/

#include "string.h"

char *str_ppd(char *string, const char *span)
{
	size_t n = str_len(span);

	string = str_rev(string);
	string = str_napd(string, span, n);
	return (str_rev(string));
}

char *str_nppd(char *string, const char *span, size_t n)
{
	string = str_rev(string);
	string = str_napd(string, span, n);
	return (str_rev(string));
}
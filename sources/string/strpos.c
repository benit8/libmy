/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strpos.c
*/

#include "string.h"

ssize_t str_pos(char *string, const char *search)
{
	char *p = str_str(string, search);

	return (p ? p - string : -1);
}

ssize_t str_npos(char *string, const char *search, size_t n)
{
	char *p = str_nstr(string, search, n);

	return (p ? p - string : -1);
}
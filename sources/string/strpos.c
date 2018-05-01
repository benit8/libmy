/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strpos.c
*/

#include "my/string.h"

ssize_t my_strpos(char *string, const char *search)
{
	char *p = my_strstr(string, search);

	return (p ? p - string : -1);
}

ssize_t my_strnpos(char *string, const char *search, size_t n)
{
	char *p = my_strnstr(string, search, n);

	return (p ? p - string : -1);
}
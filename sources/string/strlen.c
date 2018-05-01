/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strlen.c
*/

#include "my/string.h"

size_t my_strlen(const char *str)
{
	const char *s = str;

	if (!s)
		return (0);
	for (; *s != 0; s++);
	return (s - str);
}

size_t my_strnlen(const char *str, size_t max)
{
	const char *s = str;

	if (!s)
		return (0);
	for (; *s != 0 && (size_t)(s - str) <= max; s++);
	return (s - str);
}
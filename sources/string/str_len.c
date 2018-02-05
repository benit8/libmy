/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** str_len.c
*/

#include "string.h"

size_t str_len(const char *str)
{
	const char *s = str;

	for (; *s != 0; s++);
	return (s - str);
}

size_t str_nlen(const char *str, size_t max)
{
	const char *s = str;

	for (; *s != 0 && (size_t)(s - str) <= max; s++);
	return (s - str);
}
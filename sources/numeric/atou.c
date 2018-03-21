/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** atou.c
*/

#include "my/numeric.h"

size_t my_atou(const char *str)
{
	size_t res = 0;

	for (; is_digit(*str); str++)
		res = (res * 10) + (*str - '0');
	return (res);
}
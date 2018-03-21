/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** atoi.c
*/

#include "my/numeric.h"

ssize_t my_atoi(const char *str)
{
	ssize_t res = 0;

	if (*str == '+')
		return (my_atoi(str + 1));
	if (*str == '-')
		return (-my_atoi(str + 1));
	for (; is_digit(*str); str++)
		res = (res * 10) + (*str - '0');
	return (res);
}
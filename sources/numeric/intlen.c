/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** intlen.c
*/

#include "numeric.h"

size_t intlen(ssize_t n)
{
	size_t l = (n < 0) ? 2 : 1;

	for (; n <= -10 || n >= 10; n /= 10, l++);
	return (l);
}

size_t uintlen(size_t n)
{
	size_t l = 1;

	for (; n >= 10; n /= 10, l++);
	return (l);
}
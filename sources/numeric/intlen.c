/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** intlen.c
*/

#include "my/numeric.h"

size_t intlen(ssize_t n)
{
	size_t len = (n < 0) ? 2 : 1;

	for (; n <= -10 || n >= 10; n /= 10, len++);
	return (len);
}

size_t uintlen(size_t n)
{
	size_t len = 1;

	for (; n >= 10; n /= 10, len++);
	return (len);
}
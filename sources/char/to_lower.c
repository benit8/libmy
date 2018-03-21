/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** to_lower.c
*/

#include "my/char.h"

int to_lower(int c)
{
	return (is_upper(c) ? c + 32 : c);
}
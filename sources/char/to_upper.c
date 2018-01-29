/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** to_upper.c
*/

#include "char.h"

int to_upper(int c)
{
	return (is_lower(c) ? c - 32 : c);
}
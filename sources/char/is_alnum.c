/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_alnum.c
*/

#include "char.h"

bool is_alnum(int c)
{
	return (is_alpha(c) || is_digit(c));
}
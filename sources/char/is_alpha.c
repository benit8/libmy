/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_alpha.c
*/

#include "char.h"

bool is_alpha(int c)
{
	return (is_lower(c) || is_upper(c));
}
/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_upper.c
*/

#include "my/char.h"

bool is_upper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
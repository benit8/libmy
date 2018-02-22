/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_print.c
*/

#include "char.h"

bool is_print(int c)
{
	return (c >= ' ' && c <= '~');
}
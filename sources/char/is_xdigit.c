/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_xdigit.c
*/

#include "char.h"

bool is_xdigit(int c)
{
	return (is_digit(c) ||
		(c >= 'a' && c <= 'f') ||
		(c >= 'A' && c <= 'F'));
}
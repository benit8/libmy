/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_punct.c
*/

#include "char.h"

bool is_punct(int c)
{
	return ((c >= '!' && c <= '/') ||
		(c >= ':' && c <= '@') ||
		(c >= '[' && c <= '`') ||
		(c >= '{' && c <= '~'));
}
/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_cntrl.c
*/

#include "my/char.h"

bool is_cntrl(int c)
{
	return ((c >= 0 && c <= 31) || c == 127);
}
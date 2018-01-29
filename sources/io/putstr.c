/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** putstr.c
*/

#include "io.h"

void my_putstr(const char *str)
{
	write(1, str, str_len(str));
}
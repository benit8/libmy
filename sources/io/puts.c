/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** puts.c
*/

#include "my/io.h"

void my_puts(const char *str)
{
	my_putstr(str);
	my_putchar('\n');
}
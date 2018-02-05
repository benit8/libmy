/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** putchar.c
*/

#include "io.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}
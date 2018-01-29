/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_digit.c
*/

#include "char.h"

bool is_digit(int c)
{
	return (c >= '0' && c <= '9');
}
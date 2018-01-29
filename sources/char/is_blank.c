/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_blank.c
*/

#include "char.h"

bool is_blank(int c)
{
	return (c == ' ' || c == '\t');
}
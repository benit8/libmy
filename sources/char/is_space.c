/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_space.c
*/

#include "char.h"

bool is_space(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}
/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_graph.c
*/

#include "char.h"

bool is_graph(int c)
{
	return (is_alnum(c) || is_punct(c));
}
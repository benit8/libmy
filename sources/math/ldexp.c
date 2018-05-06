/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** math / ldexp.c
*/

#include "my/math.h"

double my_ldexp(double x, int exp)
{
	return (x * my_exp2(exp));
}
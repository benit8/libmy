/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ceil.c
*/

#include "my/math.h"

double my_ceil(double dbl)
{
	double n = (int)dbl;
	double dec = (dbl - n) * 100000;

	return (n + (dec > 0));
}

double my_ceilp(double dbl, int p)
{
	int pwr = my_pow(10, p);

	if (p <= 0)
		return (my_ceil(dbl));
	return (my_ceil(dbl * pwr) / pwr);
}
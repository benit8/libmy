/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** round.c
*/

#include "my/math.h"

double my_round(double x)
{
	double n = (int)x;
	double d = (x - n) * 10;

	return (n + (d >= 5));
}

double my_roundp(double x, int p)
{
	int pwr;

	if (p <= 0)
		return (my_round(x));
	pwr = my_pow(10, p);
	return (my_round(x * pwr) / pwr);
}
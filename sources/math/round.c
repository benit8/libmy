/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** round.c
*/

#include "math.h"

double my_round(double dbl)
{
	double n = (int)dbl;
	double dec = dbl - n;
	double firstDec = dec * 10;

	return (n + (firstDec >= 5));
}

double my_roundp(double dbl, int p)
{
	int pwr = my_pow(10, p);

	if (p <= 0)
		return (my_round(dbl));
	return (my_round(dbl * pwr) / pwr);
}
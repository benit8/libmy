/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** floor.c
*/

#include "math.h"

double my_floor(double dbl)
{
	return ((int)dbl);
}

double my_floorp(double dbl, int p)
{
	int pwr = my_pow(10, p);

	if (p <= 0)
		return (my_floor(dbl));
	return (my_floor(dbl * pwr) / pwr);
}
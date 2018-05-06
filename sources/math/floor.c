/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** floor.c
*/

#include "my/math.h"

double my_floor(double x)
{
	return ((int)x - (x < 0.0f));
}

double my_floorp(double x, int p)
{
	int pwr;

	if (p <= 0)
		return (my_floor(x));
	pwr = my_pow(10, p);
	return (my_floor(x * pwr) / pwr);
}
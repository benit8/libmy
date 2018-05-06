/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** math / sqrt.c
*/

#include "my/math.h"

double my_sqrt(double x)
{
	double i;

	if (x < 0.0)
		return (0.0);
	i = x / 2.0;
	while (ABS(i - (x / i)) / i > EPSILON)
		i = (i + (x / i)) / 2.0;
	return (i);
}
/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** fmod.c
*/

#include "my/math.h"

double my_fmod(double x, double y)
{
	int ir;
	int iy;
	double r;
	double w;

	if (y == 0.0)
		return (x * y) / (x * y);
	r = ABS(x);
	y = ABS(y);
	my_frexp(y, &iy);
	while (r >= y) {
		my_frexp(r, &ir);
		w = my_ldexp(y, ir - iy);
		r -= (w <= r) ? w : w * 0.5;
	}
	return ((x >= 0.0) ? r : -r);
}
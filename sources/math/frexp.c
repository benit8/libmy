/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** frexp.c
*/

#include "math.h"

double my_frexp(double value, int *eptr)
{
	union frexp_u u;

	if (value) {
		u.v = value;
		if (u.s.dbl_exp != DOUBLE_EXP_INFNAN) {
			*eptr = u.s.dbl_exp - (DOUBLE_BIAS - 1);
			u.s.dbl_exp = DOUBLE_BIAS - 1;
		}
		return (u.v);
	}
	*eptr = 0;
	return (0.0);
}
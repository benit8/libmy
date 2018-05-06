/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** pow.c
*/

#include <criterion/criterion.h>
#include <math.h>
#include "my/math.h"

Test(Math, pow)
{
	double a;
	double b;

	for (double i = -20.0; i < 20.0; i += 0.865) {
		a = my_pow(2, i);
		b = pow(2, i);
		cr_assert_float_eq(a, b, EPSILON, "(%f)	%.8f : %.8f", i, a, b);
	}
}
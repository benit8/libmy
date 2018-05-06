/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** exp.c
*/

#include <criterion/criterion.h>
#include <math.h>
#include "my/math.h"

Test(Math, exp)
{
	double a;
	double b;

	for (double i = -20.0; i < 20.0; i += 0.865) {
		a = my_exp(i);
		b = exp(i);
		cr_assert_float_eq(a, b, EPSILON, "(%f)	%.8f : %.8f", i, a, b);
	}
}
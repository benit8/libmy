/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** log.c
*/

#include <criterion/criterion.h>
#include <math.h>
#include "my/math.h"

Test(Math, log)
{
	double a;
	double b;

	for (double i = 0.0001; i < 40.0; i += 0.8654) {
		a = my_log(i);
		b = log(i);
		cr_assert_float_eq(a, b, EPSILON, "(%f)	%f : %f", i, a, b);
	}
}
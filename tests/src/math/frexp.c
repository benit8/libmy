/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** frexp.c
*/

#include <criterion/criterion.h>
#include <math.h>
#include "my/math.h"

static void test(double x)
{
	int a;
	int b;
	double aa = my_frexp(x, &a);
	double bb = frexp(x, &b);

	cr_assert_eq(a, b, "Exponents are not equal for x=%f", x);
	cr_assert_float_eq(aa, bb, EPSILON, "Mantissa are not equal for x=%f", x);
}

Test(Math, frexp)
{
	for (double i = -40.0; i < 40.0; i += 0.8654)
		test(i);
}
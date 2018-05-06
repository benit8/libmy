/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** math / ldexp.c
*/

#include <criterion/criterion.h>
#include <math.h>
#include "my/math.h"

Test(Math, ldexp)
{
	int e = 3;

	for (double i = -40.0; i < 40.0; i += 0.8654)
		cr_assert_float_eq(my_ldexp(i, e), ldexp(i, e), EPSILON);
}
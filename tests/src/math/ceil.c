/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ceil.c
*/

#include <criterion/criterion.h>
#include <math.h>
#include "my/math.h"

Test(Math, ceil)
{
	cr_expect_float_eq(my_ceil(0.0), ceil(0.0), EPSILON);
	cr_expect_float_eq(my_ceil(1.0), ceil(1.0), EPSILON);

	cr_expect_float_eq(my_ceil(-1.0000001), ceil(-1.0000001), EPSILON);
	cr_expect_float_eq(my_ceil(0.0000009), ceil(0.0000009), EPSILON);
	cr_expect_float_eq(my_ceil(1.0000001), ceil(1.0000001), EPSILON);

	cr_expect_float_eq(my_ceil(1.0000000000000001), ceil(1.0000000000000001), EPSILON);
}

Test(Math, ceilp)
{
	cr_expect_float_eq(my_ceilp(0.0, 0), 0.0, EPSILON);
	cr_expect_float_eq(my_ceilp(0.0, 1), 0.0, EPSILON);

	cr_expect_float_eq(my_ceilp(0.0000009, 2), 0.01, EPSILON);
	cr_expect_float_eq(my_ceilp(0.0000009, 6), 0.000001, EPSILON);
}
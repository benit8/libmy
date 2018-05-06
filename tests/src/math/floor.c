/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** floor.c
*/

#include <criterion/criterion.h>
#include <math.h>
#include "my/math.h"

Test(Math, floor)
{
	cr_expect_float_eq(my_floor(0.0), floor(0.0), EPSILON);
	cr_expect_float_eq(my_floor(1.0), floor(1.0), EPSILON);

	cr_expect_float_eq(my_floor(-1.0000001), floor(-1.0000001), EPSILON);
	cr_expect_float_eq(my_floor(0.0000009), floor(0.0000009), EPSILON);
	cr_expect_float_eq(my_floor(1.0000001), floor(1.0000001), EPSILON);

	cr_expect_float_eq(my_floor(1.0000000000000001), floor(1.0000000000000001), EPSILON);
}

Test(Math, floorp)
{
	cr_expect_float_eq(my_floorp(0.0, 0), 0.0, EPSILON);
	cr_expect_float_eq(my_floorp(0.0, 1), 0.0, EPSILON);

	// cr_expect_float_eq(my_floorp(0.09, 3), 0.08, EPSILON);
	// cr_expect_float_eq(my_floorp(0.09, 6), 0.000001, EPSILON);
}
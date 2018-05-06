/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** angle.c
*/

#include <criterion/criterion.h>
#include "my/math.h"

Test(Math, radians)
{
	cr_expect_float_eq(radians(  0.0), 0.0,            EPSILON);
	cr_expect_float_eq(radians( 30.0),       PI / 6.0, EPSILON);
	cr_expect_float_eq(radians( 45.0),       PI / 4.0, EPSILON);
	cr_expect_float_eq(radians( 60.0),       PI / 3.0, EPSILON);
	cr_expect_float_eq(radians( 90.0),       PI / 2.0, EPSILON);
	cr_expect_float_eq(radians(120.0), 2.0 * PI / 3.0, EPSILON);
	cr_expect_float_eq(radians(135.0), 3.0 * PI / 4.0, EPSILON);
	cr_expect_float_eq(radians(180.0),       PI,       EPSILON);
	cr_expect_float_eq(radians(270.0), 3.0 * PI / 2.0, EPSILON);
	cr_expect_float_eq(radians(360.0), 2.0 * PI,       EPSILON);
}

Test(Math, degrees)
{
	cr_expect_float_eq(degrees(0.0),              0.0, EPSILON);
	cr_expect_float_eq(degrees(      PI / 6.0),  30.0, EPSILON);
	cr_expect_float_eq(degrees(      PI / 4.0),  45.0, EPSILON);
	cr_expect_float_eq(degrees(      PI / 3.0),  60.0, EPSILON);
	cr_expect_float_eq(degrees(      PI / 2.0),  90.0, EPSILON);
	cr_expect_float_eq(degrees(2.0 * PI / 3.0), 120.0, EPSILON);
	cr_expect_float_eq(degrees(3.0 * PI / 4.0), 135.0, EPSILON);
	cr_expect_float_eq(degrees(      PI      ), 180.0, EPSILON);
	cr_expect_float_eq(degrees(3.0 * PI / 2.0), 270.0, EPSILON);
	cr_expect_float_eq(degrees(2.0 * PI      ), 360.0, EPSILON);
}
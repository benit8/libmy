/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** sqrt.c
*/

#include <criterion/criterion.h>
#include <math.h>
#include "my/math.h"

Test(Math, sqrt)
{
	cr_expect_float_eq(my_sqrt(-1), 0.0, EPSILON);
	cr_expect_float_eq(my_sqrt(0), sqrt(0), EPSILON);
	cr_expect_float_eq(my_sqrt(1), sqrt(1), EPSILON);
	cr_expect_float_eq(my_sqrt(2), sqrt(2), EPSILON);
	cr_expect_float_eq(my_sqrt(2.4865), sqrt(2.4865), EPSILON);
}
/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** parsing / calc.c
*/

#include <criterion/criterion.h>
#include "my/parsing/calc.h"

Test(Parsing, calc)
{
	cr_expect_eq(calc(NULL), 0);
	cr_expect_eq(calc(""), 0);

	cr_expect_eq(calc("  	 "), 0);
	cr_expect_eq(calc("Hello"), 0);

	cr_expect_eq(calc("0"), 0);
	cr_expect_eq(calc("-0"), 0);

	cr_expect_eq(calc("1 + 1"), 2);
	cr_expect_eq(calc("-1 + 1"), 0);

	cr_expect_eq(calc("4 - 1"), 3);
	cr_expect_eq(calc("1 - -1"), 2);

	cr_expect_eq(calc("-1 * 2"), -2);
	cr_expect_eq(calc("-2 * -2"), 4);

	cr_expect_eq(calc("8 / 2"), 4);
	cr_expect_eq(calc("8 / 2.5"), 3);

	cr_expect_eq(calc("9 % 2"), 1);
	cr_expect_eq(calc("4 % 2.666"), 1);

	cr_expect_eq(calc("4 ^ 2"), 16);
	cr_expect_eq(calc("1.33400 ^ 5"), 4);
}

Test(Parsing, fcalc)
{
	double epsilon = 1.0 / 1000000.0;

	cr_expect_float_eq(fcalc(NULL), 0, epsilon);
	cr_expect_float_eq(fcalc(""), 0, epsilon);

	cr_expect_float_eq(fcalc("  	 "), 0, epsilon);
	cr_expect_float_eq(fcalc("Hello"), 0, epsilon);

	cr_expect_float_eq(fcalc("0"), 0, epsilon);
	cr_expect_float_eq(fcalc("-0"), 0, epsilon);

	cr_expect_float_eq(fcalc("1 + 1"), 2, epsilon);
	cr_expect_float_eq(fcalc("-1 + 1"), 0, epsilon);

	cr_expect_float_eq(fcalc("4 - 1"), 3, epsilon);
	cr_expect_float_eq(fcalc("1 - -1"), 2, epsilon);

	cr_expect_float_eq(fcalc("-1 * 2"), -2, epsilon);
	cr_expect_float_eq(fcalc("-2 * -2"), 4, epsilon);

	cr_expect_float_eq(fcalc("8 / 2"), 4, epsilon);
	cr_expect_float_eq(fcalc("8 / 2.5"), 3.2, epsilon);

	cr_expect_float_eq(fcalc("9 % 2"), 1, epsilon);
	cr_expect_float_eq(fcalc("4 % 2.666"), 1.33400, epsilon);

	cr_expect_float_eq(fcalc("4 ^ 2"), 16, epsilon);
	cr_expect_float_eq(fcalc("1.33400 ^ 5"), 4.22453729, epsilon);
}
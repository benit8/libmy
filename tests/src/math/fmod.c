/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** fmod.c
*/

#include <criterion/criterion.h>
#include <math.h>
#include "my/math.h"

Test(Math, fmod)
{
	double a = 4.0;

	for (double i = -40.0; i < 40.0; i += 0.8654)
		cr_assert_float_eq(my_fmod(a, i), fmod(a, i), EPSILON);
}
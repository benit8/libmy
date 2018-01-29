/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** pow.c
*/

#include "math.h"

double my_pow(double x, double y)
{
	return (my_exp(my_log(x) * y));
}
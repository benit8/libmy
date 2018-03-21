/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** fmod.c
*/

#include "my/math.h"

double my_fmod(double a, double b)
{
	return (a - b * my_floor(a / b));
}
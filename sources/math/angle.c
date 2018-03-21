/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** angle.c
*/

#include "my/math.h"

double radians(double degrees)
{
	return (2.0 * PI * degrees / 360.0);
}

double degrees(double radians)
{
	return (360.0 * radians / (2.0 * PI));
}
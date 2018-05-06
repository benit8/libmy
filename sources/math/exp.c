/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** exp.c
*/

#include "my/math.h"

double my_exp(double x)
{
	return (my_exp2(DOUBLE_LOG2OFE * x));
}

double my_exp2(double x)
{
	double ipart = my_floor(x + 0.5);
	double fpart = x - ipart;
	double px;
	double qx;
	udi_t epart;

	epart.s.i0 = 0;
	epart.s.i1 = (((int)ipart) + DOUBLE_BIAS) << 20;
	x = fpart * fpart;
	px = EXP2_P0 * x + EXP2_P1;
	qx = x + EXP2_Q0;
	px = px * x + EXP2_P2;
	qx = qx * x + EXP2_Q1;
	px = px * fpart;
	x = 1.0 + 2.0 * (px / (qx - px));
	return (epart.f * x);
}

double my_exp10(double x)
{
	return (my_exp2(DOUBLE_LOG2OF10 * x));
}
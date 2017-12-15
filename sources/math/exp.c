/*
** exp.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/Math
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Dec 13 15:42:39 2017 Benoit Lormeau
** Last update Wed Dec 13 15:42:39 2017 Benoit Lormeau
*/

#include "math.h"

double my_exp(double x)
{
	return (my_exp2(DOUBLE_LOG2OFE * x));
}

double my_exp2(double x)
{
	double ipart;
	double fpart;
	double px;
	double qx;
	udi_t epart;

	ipart = my_floor(x + 0.5);
	fpart = x - ipart;
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
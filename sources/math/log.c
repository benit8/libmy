/*
** log.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/Math
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Dec 13 14:57:53 2017 Benoit Lormeau
** Last update Wed Dec 13 14:57:53 2017 Benoit Lormeau
*/

#include "math.h"

double my_log(double x)
{
	int k;
	double f = my_frexp(x, &k);
	double h;
	double r;
	double s[3];
	double t[2];

	if (f < DOUBLE_SQRT2 / 2) {
		f *= 2;
		k--;
	}
	f -= 1;
	s[0] = f / (2 + f);
	s[1] = s[0] * s[0];
	s[2] = s[1] * s[1];
	t[0] = s[1] * (LOG_1 + s[2] * (LOG_3 + s[2] * (LOG_5 + s[2] * LOG_7)));
	t[1] = s[2] * (LOG_2 + s[2] * (LOG_4 + s[2] * LOG_6));
	r = t[0] + t[1];
	h = 0.5 * f * f;
	return (k * LOG_LN2H - ((h - (s[0] * (h + r) + k * LOG_LN2L)) - f));
}
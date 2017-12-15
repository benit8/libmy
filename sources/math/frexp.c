/*
** frexp.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/Math
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Dec 13 16:16:11 2017 Benoit Lormeau
** Last update Wed Dec 13 16:16:11 2017 Benoit Lormeau
*/

#include "math.h"

double my_frexp(double value, int *eptr)
{
	union frexp_u u;

	if (value) {
		u.v = value;
		if (u.s.dbl_exp != DOUBLE_EXP_INFNAN) {
			*eptr = u.s.dbl_exp - (DOUBLE_BIAS - 1);
			u.s.dbl_exp = DOUBLE_BIAS - 1;
		}
		return (u.v);
	}
	*eptr = 0;
	return (0.0);
}
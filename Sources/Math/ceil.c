/*
** ceil.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Math
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Nov 13 11:02:30 2017 Benoit Lormeau
** Last update Mon Nov 13 11:38:41 2017 Benoit Lormeau
*/

#include "Math.h"

double my_ceil(double dbl)
{
	double n = (int)dbl;
	double dec = (dbl - n) * 100000;

	return (n + (dec > 0));
}

double my_ceilp(double dbl, int p)
{
	int pwr = my_pow(10, p);

	if (p <= 0)
		return (my_ceil(dbl));
	return (my_ceil(dbl * pwr) / pwr);
}
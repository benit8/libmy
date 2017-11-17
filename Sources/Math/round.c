/*
** round.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Math
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Nov 13 10:44:31 2017 Benoit Lormeau
** Last update Mon Nov 13 11:38:14 2017 Benoit Lormeau
*/

#include "Math.h"

double my_round(double dbl)
{
	double n = (int)dbl;
	double dec = dbl - n;
	double firstDec = dec * 10;

	return (n + (firstDec >= 5));
}

double my_roundp(double dbl, int p)
{
	int pwr = my_pow(10, p);

	if (p <= 0)
		return (my_round(dbl));
	return (my_round(dbl * pwr) / pwr);
}
/*
** floor.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Math
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Nov 13 11:01:32 2017 Benoit Lormeau
** Last update Mon Nov 13 11:38:29 2017 Benoit Lormeau
*/

#include "math.h"

double my_floor(double dbl)
{
	return ((int)dbl);
}

double my_floorp(double dbl, int p)
{
	int pwr = my_pow(10, p);

	if (p <= 0)
		return (my_floor(dbl));
	return (my_floor(dbl * pwr) / pwr);
}
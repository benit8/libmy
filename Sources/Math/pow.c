/*
** pow.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Math
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Fri Nov 10 16:02:51 2017 Benoit Lormeau
** Last update Fri Nov 10 16:04:38 2017 Benoit Lormeau
*/

#include "Math.h"

double my_pow(double n, int p)
{
	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	return (n * my_pow(n, p - 1));
}
/*
** pow.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Math
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Fri Nov 10 16:02:51 2017 Benoit Lormeau
** Last update Fri Nov 10 16:04:38 2017 Benoit Lormeau
*/

#include "math.h"

double my_pow(double x, double y)
{
	return (my_exp(my_log(x) * y));
}
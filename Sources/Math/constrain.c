/*
** constrain.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Math
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Fri Oct 27 15:20:11 2017 Benoit Lormeau
** Last update Fri Oct 27 15:20:11 2017 Benoit Lormeau
*/

#include "libmy.h"

ssize_t constrain(ssize_t val, ssize_t min, ssize_t max)
{
	if (val < min)
		return (min);
	else if (val > max)
		return (max);
	return (val);
}

size_t uconstrain(size_t val, size_t max)
{
	return (val > max ? max : val);
}

float fconstrain(float val, float min, float max)
{
	if (val < min)
		return (min);
	else if (val > max)
		return (max);
	return (val);
}

double dconstrain(double val, double min, double max)
{
	if (val < min)
		return (min);
	else if (val > max)
		return (max);
	return (val);
}
/*
** angle.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Math
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 30 09:31:11 2017 Benoit Lormeau
** Last update Mon Oct 30 09:31:11 2017 Benoit Lormeau
*/

#include "math.h"

double radians(double degrees)
{
	return (2.0 * PI * degrees / 360.0);
}

double degrees(double radians)
{
	return (360.0 * radians / (2.0 * PI));
}
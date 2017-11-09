/*
** angle.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Math
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 30 09:31:11 2017 Benoit Lormeau
** Last update Mon Oct 30 09:31:11 2017 Benoit Lormeau
*/

#include "Math.h"

double radians(double degrees)
{
	return (2 * PI * degrees / 360);
}

double degrees(double radians)
{
	return (360 * radians / (2 * PI));
}
/*
** fmod.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/Math
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Dec 13 14:04:41 2017 Benoit Lormeau
** Last update Wed Dec 13 14:04:41 2017 Benoit Lormeau
*/

#include "math.h"

double my_fmod(double a, double b)
{
	return (a - b * my_floor(a / b));
}
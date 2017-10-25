/*
** abs.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Numeric
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 10:08:56 2017 Benoit Lormeau
** Last update Wed Oct 25 10:08:56 2017 Benoit Lormeau
*/

#include "libmy.h"

int my_abs(int n)
{
	return (n < 0 ? -n : n);
}
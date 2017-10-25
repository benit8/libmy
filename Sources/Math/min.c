/*
** min.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Math
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 16:17:02 2017 Benoit Lormeau
** Last update Wed Oct 25 16:17:02 2017 Benoit Lormeau
*/

#include "libmy.h"

ssize_t my_min(ssize_t a, ssize_t b)
{
	return (a < b ? a : b);
}

size_t my_umin(size_t a, size_t b)
{
	return (a < b ? a : b);
}
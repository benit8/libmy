/*
** my_getnbr.c for libmy in /mnt/data/Delivery/Perso/libmy/puts
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 09:56:24 2017 Benoit Lormeau
** Last update Mon Oct 23 09:56:24 2017 Benoit Lormeau
*/

#include "libmy.h"

int my_getnbr(const char *str)
{
	int res = 0;

	if (*str == '+')
		return (my_getnbr(str + 1));
	if (*str == '-')
		return (-my_getnbr(str + 1));
	for (; *str >= '0' && *str <= '9'; str++)
		res = (res * 10) + (*str - '0');
	return (res);
}
/*
** strnlen.c for libmy in /mnt/data/Delivery/Perso/libmy/string
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 16:56:56 2017 Benoit Lormeau
** Last update Mon Oct 23 16:56:56 2017 Benoit Lormeau
*/

#include "libmy.h"

size_t my_strnlen(const char *str, size_t max)
{
	register const char *s = str;

	for (; *s != 0 && (size_t)(s - str) < max; s++);
	return (s - str);
}
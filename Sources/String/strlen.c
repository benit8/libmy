/*
** strlen.c for libmy in /mnt/data/Delivery/Perso/libmy/string
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 09:57:50 2017 Benoit Lormeau
** Last update Mon Oct 23 09:57:50 2017 Benoit Lormeau
*/

#include "libmy.h"

size_t my_strlen(const char *str)
{
	register const char *s = str;

	for (; *s != 0; s++);
	return (s - str);
}
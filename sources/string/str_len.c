/*
** strlen.c for libmy in /mnt/data/Delivery/Perso/libmy/string
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 09:57:50 2017 Benoit Lormeau
** Last update Mon Oct 23 09:57:50 2017 Benoit Lormeau
*/

#include "string.h"

size_t str_len(const char *str)
{
	const char *s = str;

	for (; *s != 0; s++);
	return (s - str);
}

size_t str_nlen(const char *str, size_t max)
{
	const char *s = str;

	for (; *s != 0 && (size_t)(s - str) <= max; s++);
	return (s - str);
}
/*
** str_pos.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/String
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 22:53:41 2017 Benoit Lormeau
** Last update Wed Oct 25 22:53:41 2017 Benoit Lormeau
*/

#include "String.h"

ssize_t str_pos(char *string, const char *search)
{
	char *p = str_str(string, search);

	return (p ? p - string : -1);
}
/*
** to_upper.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Char
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 24 14:46:18 2017 Benoit Lormeau
** Last update Tue Oct 24 14:46:18 2017 Benoit Lormeau
*/

#include "char.h"

int to_upper(int c)
{
	return (is_lower(c) ? c - 32 : c);
}
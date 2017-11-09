/*
** to_lower.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Char
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 24 14:44:42 2017 Benoit Lormeau
** Last update Tue Oct 24 14:44:42 2017 Benoit Lormeau
*/

#include "Char.h"

int to_lower(int c)
{
	return (is_upper(c) ? c + 32 : c);
}
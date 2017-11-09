/*
** is_alpha.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Char
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 24 14:51:11 2017 Benoit Lormeau
** Last update Tue Oct 24 14:51:11 2017 Benoit Lormeau
*/

#include "Char.h"

bool is_alpha(int c)
{
	return (is_lower(c) || is_upper(c));
}
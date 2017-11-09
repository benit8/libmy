/*
** is_alnum.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Char
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 24 14:53:16 2017 Benoit Lormeau
** Last update Tue Oct 24 14:53:16 2017 Benoit Lormeau
*/

#include "Char.h"

bool is_alnum(int c)
{
	return (is_alpha(c) || is_digit(c));
}
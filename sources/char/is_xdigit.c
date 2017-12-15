/*
** is_xdigit.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Char
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 24 15:09:57 2017 Benoit Lormeau
** Last update Tue Oct 24 15:09:57 2017 Benoit Lormeau
*/

#include "char.h"

bool is_xdigit(int c)
{
	return (is_digit(c) ||
		(c >= 'a' && c <= 'f') ||
		(c >= 'A' && c <= 'F'));
}
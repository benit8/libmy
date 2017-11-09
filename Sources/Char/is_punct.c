/*
** is_punct.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Char
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 24 15:01:40 2017 Benoit Lormeau
** Last update Tue Oct 24 15:01:40 2017 Benoit Lormeau
*/

#include "Char.h"

bool is_punct(int c)
{
	return ((c >= '!' && c <= '/') ||
		(c >= ':' && c <= '@') ||
		(c >= '[' && c <= '`') ||
		(c >= '{' && c <= '~'));
}
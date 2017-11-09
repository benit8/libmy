/*
** is_lower.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Char
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 24 14:50:05 2017 Benoit Lormeau
** Last update Tue Oct 24 14:50:05 2017 Benoit Lormeau
*/

#include "Char.h"

bool is_lower(int c)
{
	return (c >= 'a' && c <= 'z');
}
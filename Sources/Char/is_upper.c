/*
** is_upper.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Char
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 24 14:50:36 2017 Benoit Lormeau
** Last update Tue Oct 24 14:50:36 2017 Benoit Lormeau
*/

#include "libmy.h"

bool is_upper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
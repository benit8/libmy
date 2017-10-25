/*
** is_digit.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Char
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 24 14:51:47 2017 Benoit Lormeau
** Last update Tue Oct 24 14:51:47 2017 Benoit Lormeau
*/

#include "libmy.h"

bool is_digit(int c)
{
	return (c >= '0' && c <= '9');
}
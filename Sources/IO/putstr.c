/*
** my_putstr.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/IO
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 09:57:23 2017 Benoit Lormeau
** Last update Mon Oct 23 09:57:23 2017 Benoit Lormeau
*/

#include "IO.h"

void my_putstr(const char *str)
{
	write(1, str, str_len(str));
}
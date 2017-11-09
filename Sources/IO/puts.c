/*
** puts.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/IO
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 09:59:15 2017 Benoit Lormeau
** Last update Mon Oct 23 09:59:15 2017 Benoit Lormeau
*/

#include "IO.h"

void my_puts(const char *str)
{
	my_putstr(str);
	my_putchar('\n');
}
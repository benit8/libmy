/*
** my_putchar.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/IO
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 09:58:25 2017 Benoit Lormeau
** Last update Mon Oct 23 09:58:25 2017 Benoit Lormeau
*/

#include "io.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}
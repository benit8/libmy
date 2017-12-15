/*
** is_print.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Char
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 24 15:06:57 2017 Benoit Lormeau
** Last update Tue Oct 24 15:06:57 2017 Benoit Lormeau
*/

#include "char.h"

bool is_print(int c)
{
	return (is_graph(c) || is_space(c));
}
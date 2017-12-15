/*
** is_graph.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Char
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 24 15:00:31 2017 Benoit Lormeau
** Last update Tue Oct 24 15:00:31 2017 Benoit Lormeau
*/

#include "char.h"

bool is_graph(int c)
{
	return (is_alnum(c) || is_punct(c));
}
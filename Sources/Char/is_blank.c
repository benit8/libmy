/*
** is_blank.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Char
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 22:57:38 2017 Benoit Lormeau
** Last update Wed Oct 25 22:57:38 2017 Benoit Lormeau
*/

#include "Char.h"

bool is_blank(int c)
{
	return (c == ' ' || c == '\t');
}
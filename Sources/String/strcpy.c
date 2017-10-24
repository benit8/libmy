/*
** strcpy.c for libmy in /mnt/data/Delivery/Perso/libmy/string
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 10:50:38 2017 Benoit Lormeau
** Last update Mon Oct 23 10:50:38 2017 Benoit Lormeau
*/

#include "libmy.h"

char *my_strcpy(char *dest, const char *src)
{
	return (my_strncpy(dest, src, my_strlen(src)));
}
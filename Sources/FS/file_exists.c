/*
** file_exists.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/FS
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 24 16:14:44 2017 Benoit Lormeau
** Last update Tue Oct 24 16:14:44 2017 Benoit Lormeau
*/

#include "libmy.h"

bool file_exists(const char *filepath)
{
	return (access(filepath, F_OK) != -1);
}
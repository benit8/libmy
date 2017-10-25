/*
** file_readable.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/FS
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 10:47:30 2017 Benoit Lormeau
** Last update Wed Oct 25 10:47:30 2017 Benoit Lormeau
*/

#include "libmy.h"

bool file_readable(const char *filepath)
{
	return (access(filepath, R_OK) != -1);
}
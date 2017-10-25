/*
** file.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/FS
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 14:27:21 2017 Benoit Lormeau
** Last update Wed Oct 25 14:27:21 2017 Benoit Lormeau
*/

#include "libmy.h"

char **file(const char *filepath)
{
	char *content = file_get_contents(filepath);
	char **array = explode("\n", content);

	my_free(content);
	return (array);
}
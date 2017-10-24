/*
** file_get_contents.c for libmy in /mnt/data/Delivery/Perso/libmy/fs
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 14:48:25 2017 Benoit Lormeau
** Last update Mon Oct 23 14:48:25 2017 Benoit Lormeau
*/

#include "libmy.h"

char *file_get_contents(char *file)
{
	char *buffer = NULL;
	int fd = open(file, O_RDONLY);
	size_t size = 0;

	if (fd == -1)
		return (NULL);
	lseek(fd, 0, SEEK_END);
	size = lseek(fd, 0, SEEK_CUR);
	lseek(fd, 0, SEEK_SET);
	buffer = my_calloc(size + 1, sizeof(char));
	if (buffer != NULL){
		if (read(fd, buffer, sizeof(char) * size) != -1)
			return (buffer);
		my_free(buffer);
	}
	close(fd);
	return (NULL);
}
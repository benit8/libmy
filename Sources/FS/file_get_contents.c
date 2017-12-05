/*
** file_get_contents.c for libmy in /mnt/data/Delivery/Perso/libmy/fs
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 14:48:25 2017 Benoit Lormeau
** Last update Mon Oct 23 14:48:25 2017 Benoit Lormeau
*/

#include "FS.h"

char *file_get_contents(const char *file)
{
	size_t size = 0;
	char *buffer = NULL;
	int fd = open(file, O_RDONLY);

	if (fd == -1)
		return (NULL);
	size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	buffer = my_calloc(size + 1, sizeof(char));
	if (buffer == NULL){
		close(fd);
		return (NULL);
	}
	if (read(fd, buffer, sizeof(char) * size) == -1){
		my_free(buffer);
		buffer = NULL;
	}
	close(fd);
	return (buffer);
}
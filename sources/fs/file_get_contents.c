/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** file_get_contents.c
*/

#include "fs.h"

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
	if (buffer == NULL) {
		close(fd);
		return (NULL);
	}
	if (read(fd, buffer, sizeof(char) * size) == -1)
		my_free(buffer);
	close(fd);
	return (buffer);
}
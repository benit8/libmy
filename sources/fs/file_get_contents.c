/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** file_get_contents.c
*/

#include "my/fs.h"

char *file_get_contents(const char *file)
{
	char *buffer = NULL;
	int fd = open(file, O_RDONLY);
	size_t size = 0;

	if (fd < 0)
		return (NULL);
	size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	buffer = my_calloc(size + 1, sizeof(char));
	if (buffer) {
		if (read(fd, buffer, sizeof(char) * size) == -1) {
			my_free(buffer);
			buffer = NULL;
		}
	}
	close(fd);
	return (buffer);
}
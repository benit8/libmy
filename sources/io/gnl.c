/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** gnl.c
*/

#include "io.h"

char *gnl(const int fd)
{
	char buff[1];
	char *line = my_calloc(1, sizeof(char));
	int r;

	while (1) {
		r = read(fd, buff, 1);
		if (r != 1 || buff[0] == '\n')
			break;
		line = str_napd(line, buff, 1);
	}
	if (r == 1 || line[0] != '\0')
		return (line);
	my_free(line);
	return (NULL);
}
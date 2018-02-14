/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** get_next_line
*/

#include "io.h"

char *gnl(const int fd)
{
	char *line = my_calloc(BUFFER_SIZE, sizeof(char));
	char buff[1];
	int r = 0;

	while (1) {
		r = read(fd, buff, 1);
		if (r != 1 || buff[0] == '\n')
			break;
		line = str_napd(line, buff, 1);
	}
	if (r == 1)
		return (line);
	my_free(line);
	return (NULL);
}

char *fgnl(FILE *fp)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read = get_line(&line, &len, fp);

	if (read == -1) {
		if (line)
			my_free(line);
		return (NULL);
	}
	line[read - 1] = '\0';
	return (line);
}
/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** file_put_contents.c
*/

#include "fs.h"

bool file_put_contents(const char *filepath, char *contents, bool append)
{
	ssize_t r = 0;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	int flags = O_CREAT | O_WRONLY | (append ? O_APPEND : 0);
	int fd = open(filepath, flags, mode);

	if (fd == -1)
		return (false);
	r = write(fd, contents, str_len(contents));
	close(fd);
	return (r != -1);
}
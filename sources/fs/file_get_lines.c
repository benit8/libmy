/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** file_get_lines.c
*/

#include "fs.h"

char **file_get_lines(const char *filepath)
{
	char *content = file_get_contents(filepath);
	char **array = NULL;

	if (content) {
		array = explode("\n", content);
		my_free(content);
	}
	return (array);
}
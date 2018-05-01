/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_strreplace.c
*/

#include "my/string.h"

char *my_strreplace(char *subject, const char *search, const char *replace)
{
	char *output = NULL;
	ssize_t pos = 0;

	if (my_strempty(search) || replace == NULL || my_strempty(subject))
		return (NULL);
	output = my_calloc(1, sizeof(char));
	pos = my_strpos(subject, search);
	if (pos == -1)
		return (subject);
	for (; pos != -1; pos = my_strpos(subject, search)) {
		output = my_strnapd(output, subject, pos);
		output = my_strapd(output, replace);
		subject += pos + my_strlen(search);
	}
	output = my_strapd(output, subject);
	return (output);
}
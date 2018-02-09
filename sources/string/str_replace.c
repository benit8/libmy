/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** str_replace.c
*/

#include "string.h"

char *str_replace(const char *search, const char *replace, char *subject)
{
	char *output = NULL;
	ssize_t pos = 0;
	size_t searchLen = str_len(search);

	if (str_empty(search) || replace == NULL || str_empty(subject))
		return (NULL);
	output = my_calloc(1, sizeof(char));
	pos = str_pos(subject, search);
	if (pos == -1)
		return (subject);
	for (; pos != -1; pos = str_pos(subject, search)){
		output = str_napd(output, subject, pos);
		output = str_apd(output, replace);
		subject += pos + searchLen;
	}
	output = str_apd(output, subject);
	return (output);
}
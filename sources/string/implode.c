/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** implode.c
*/

#include "string.h"

static
size_t implode_get_length(char **array, const char *glue)
{
	size_t length = 0;

	for (size_t i = 0; array[i] != NULL; ++i) {
		if (i > 0)
			length += str_len(glue);
		length += str_len(array[i]);
	}
	return (length);
}

char *implode(char **array, const char *glue)
{
	char *output = NULL;
	size_t length = 0;

	if (array == NULL || array[0] == NULL)
		return (NULL);
	length = implode_get_length(array, glue);
	output = my_calloc(length + 1, sizeof(char));
	if (!output)
		return (NULL);
	for (size_t i = 0; array[i] != NULL; ++i) {
		if (i > 0)
			output = str_apd(output, glue);
		output = str_apd(output, array[i]);
	}
	return (output);
}
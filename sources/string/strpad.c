/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strpad.c
*/

#include "my/string.h"

char *my_strpadr(const char *string, const char *pad, size_t pad_size)
{
	size_t string_len = my_strlen(string);
	size_t pad_len = my_strlen(pad);
	char *output = NULL;

	if (pad_size <= string_len)
		return (my_strdup(string));
	output = my_calloc(pad_size + 1, sizeof(char));
	my_strcpy(output, string);
	for (size_t i = string_len; i < pad_size; i += pad_len)
		my_strncat(output, pad, MIN(pad_size - i, pad_len));
	return (output);
}

char *my_strpadl(const char *string, const char *pad, size_t pad_size)
{
	size_t string_len = my_strlen(string);
	size_t pad_len = my_strlen(pad);
	size_t pad_space = 0;
	char *output = NULL;

	if (pad_size <= string_len)
		return (my_strdup(string));
	output = my_calloc(pad_size + 1, sizeof(char));
	pad_space = pad_size - string_len;
	for (size_t i = 0; i < pad_space; i += pad_len)
		my_strncat(output, pad, MIN(pad_space - i, pad_len));
	my_strcat(output, string);
	return (output);
}

char *my_strpad(const char *string, const char *pad, size_t pad_size)
{
	size_t string_len = my_strlen(string);
	size_t pad_left = (pad_size - string_len) / 2;
	char *output1 = my_strpadl(string, pad, pad_left + string_len);
	char *output2 = my_strpadr(output1, pad, pad_size);

	my_free(output1);
	return (output2);
}
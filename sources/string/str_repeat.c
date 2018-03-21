/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** str_repeat.c
*/

#include "my/string.h"

char *str_repeat(char *str, size_t times)
{
	char *output = NULL;
	size_t len = 0;

	if (str == NULL)
		return (NULL);
	len = str_len(str);
	if (!len || !times)
		return (str_dup(""));
	output = my_calloc(len * times + 1, sizeof(char));
	for (size_t i = 0; i < times; ++i)
		output = str_apd(output, str);
	return (output);
}
/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_strrepeat.c
*/

#include "my/string.h"

char *my_strrepeat(char *str, size_t times)
{
	char *output = NULL;
	size_t len = 0;

	if (str == NULL)
		return (NULL);
	len = my_strlen(str);
	if (!len || !times)
		return (my_strdup(""));
	output = my_calloc(len * times + 1, sizeof(char));
	for (size_t i = 0; i < times; ++i)
		output = my_strapd(output, str);
	return (output);
}
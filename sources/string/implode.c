/*
** implode.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/String
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 10:50:54 2017 Benoit Lormeau
** Last update Wed Oct 25 10:50:54 2017 Benoit Lormeau
*/

#include "string.h"

char *implode(const char *glue, char **array)
{
	char *output;
	size_t length = 0;

	if (array == NULL || array[0] == NULL)
		return (NULL);
	for (size_t i = 0; array[i] != NULL; ++i){
		if (i > 0)
			length += str_len(glue);
		length += str_len(array[i]);
	}
	output = my_calloc(length + 1, sizeof(char));
	output = str_apd(output, array[0]);
	for (size_t i = 1; array[i] != NULL; ++i){
		output = str_apd(output, glue);
		output = str_apd(output, array[i]);
	}
	return (output);
}
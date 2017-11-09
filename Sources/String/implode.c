/*
** implode.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/String
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 10:50:54 2017 Benoit Lormeau
** Last update Wed Oct 25 10:50:54 2017 Benoit Lormeau
*/

#include "String.h"

char *implode(const char *glue, char **array)
{
	char *output;

	if (array == NULL || array[0] == NULL)
		return (NULL);
	output = str_dup(array[0]);
	for (size_t i = 1; array[i] != NULL; ++i){
		output = str_apd(output, glue);
		output = str_apd(output, array[i]);
	}
	return (output);
}
/*
** implode.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/String
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 10:50:54 2017 Benoit Lormeau
** Last update Wed Oct 25 10:50:54 2017 Benoit Lormeau
*/

#include "libmy.h"

char *implode(const char *glue, char **array)
{
	char *output;

	if (array == NULL || array[0] == NULL)
		return (NULL);
	output = my_strdup(array[0]);
	for (size_t i = 1; array[i] != NULL; ++i){
		output = my_strapd(output, glue);
		output = my_strapd(output, array[i]);
	}
	return (output);
}
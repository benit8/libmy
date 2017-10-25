/*
** strrpt.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/String
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 14:44:59 2017 Benoit Lormeau
** Last update Wed Oct 25 14:44:59 2017 Benoit Lormeau
*/

#include "libmy.h"

char *str_repeat(char *str, size_t times)
{
	char *output = NULL;
	size_t len;

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
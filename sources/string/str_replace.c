/*
** str_replace.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/String
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 23:26:04 2017 Benoit Lormeau
** Last update Wed Oct 25 23:26:04 2017 Benoit Lormeau
*/

#include "string.h"

char *str_replace(const char *search, const char *replace, char *subject)
{
	char *output;
	ssize_t pos;
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
/*
** parse.c for MyINI in /mnt/data/Delivery/Perso/MyINI/src
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 11 13:34:08 2017 Benoit Lormeau
** Last update Mon Dec 11 13:34:08 2017 Benoit Lormeau
*/

#include "parsing/ini.h"

ini_data_t *ini_parse(char *ini_string)
{
	ini_data_t *ini = ini_init();
	char **lines = explode("\n", ini_string);

	for (size_t i = 0; lines[i] != NULL; i++) {
		lines[i] = ini_epur_line(lines[i]);
		if (!str_empty(lines[i]))
			ini_parse_line(ini, lines[i]);
		my_free(lines[i]);
	}
	my_free(lines);
	return (ini);
}

ini_data_t *ini_parse_file(const char *filepath)
{
	char *content = file_get_contents(filepath);
	ini_data_t *ini;

	if (content == NULL)
		return (NULL);
	ini = ini_parse(content);
	my_free(content);
	return (ini);
}
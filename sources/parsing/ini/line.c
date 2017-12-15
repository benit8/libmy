/*
** line.c for MyINI in /mnt/data/Delivery/Perso/MyINI/src
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 11 15:03:20 2017 Benoit Lormeau
** Last update Mon Dec 11 15:03:20 2017 Benoit Lormeau
*/

#include "parsing/ini.h"

bool ini_parse_line(ini_data_t *ini, char *line)
{
	if (str_match(line, "[/*]"))
		return (ini_leave_section(ini, line));
	else if (str_match(line, "[*]"))
		return (ini_enter_section(ini, line));
	else
		return (ini_parse_var(ini, line));
	return (false);
}

char *ini_epur_line(char *line)
{
	line = str_trim(line);
	for (char *l = line; *l != '\0'; l++) {
		if (*l == ';') {
			*l = '\0';
			break;
		}
	}
	return (line);
}
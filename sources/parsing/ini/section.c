/*
** section.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/parsing/INI
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Dec 12 10:23:22 2017 Benoit Lormeau
** Last update Tue Dec 12 10:23:22 2017 Benoit Lormeau
*/

#include "parsing/ini.h"

static char *ini_get_section_name(char *line)
{
	char *name;

	if (line[1] != '/')
		name = str_ndup(line + 1, str_len(line) - 2);
	else
		name = str_ndup(line + 2, str_len(line) - 3);
	if (str_empty(name))
		goto fail;
	for (size_t i = 0; i < str_len(name); ++i) {
		if (!is_alnum(name[i]))
			goto fail;
	}
	return (name);
fail:
	my_free(name);
	return (NULL);
}

bool ini_enter_section(ini_data_t *ini, char *line)
{
	char *sec_name = ini_get_section_name(line);

	if (!sec_name) {
		my_dprintf(2, "INI: invalid section name '%s'\n", sec_name);
		return (false);
	}
	if (!str_empty(ini->var_path))
		ini->var_path = str_apd(ini->var_path, ":");
	ini->var_path = str_apd(ini->var_path, sec_name);
	my_free(sec_name);
	return (true);
}

bool ini_leave_section(ini_data_t *ini, char *line)
{
	char *sec_name = ini_get_section_name(line);
	char *pos;
	size_t len;

	if (!sec_name) {
		my_dprintf(2, "INI: invalid section name '%s'\n", sec_name);
		return (false);
	}
	len = str_len(sec_name);
	pos = str_str(ini->var_path, sec_name);
	if (!pos || *(pos + len) != '\0') {
		my_dprintf(2, "INI: invalid section closing '%s'\n", sec_name);
		return (false);
	}
	mem_set(pos, 0, len);
	len = str_len(ini->var_path);
	if (ini->var_path[len - 1] == ':')
		ini->var_path[len - 1] = '\0';
	my_free(sec_name);
	return (true);
}
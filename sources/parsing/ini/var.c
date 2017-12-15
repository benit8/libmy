/*
** ini_var.c for MyINI in /mnt/data/Delivery/Perso/MyINI/src
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 11 15:57:04 2017 Benoit Lormeau
** Last update Mon Dec 11 15:57:04 2017 Benoit Lormeau
*/

#include "parsing/ini.h"

bool ini_parse_var(ini_data_t *ini, char *line)
{
	char **parts = explode("=", line);
	bool r = false;

	if (!parts || tab_size(parts) < 2){
		my_dprintf(2, "INI: Syntax error '%s'", line);
		tab_free(parts);
		return (false);
	}
	parts[0] = str_trim(parts[0]);
	parts[1] = str_trim(parts[1]);
	if (str_match(parts[0], "*[]"))
		r = ini_insert_array(ini, parts[0], parts[1]);
	else
		r = ini_insert_var(ini, parts[0], parts[1]);
	my_free(parts[0]);
	my_free(parts);
	return (r);
}

bool ini_insert_var(ini_data_t *ini, char *var_name, char *val)
{
	char *varpath;
	var_t *var;

	if (str_empty(ini->var_path))
		varpath = str_dup(var_name);
	else
		my_asprintf(&varpath, "%s:%s", ini->var_path, var_name);
	if (!varpath)
		return (false);
	var = var_create(STRING, val);
	table_put(ini->vars, varpath, var);
	my_free(varpath);
	return (true);
}
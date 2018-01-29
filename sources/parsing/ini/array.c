/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** array.c
*/

#include "parsing/ini.h"

static bool ini_var_array_append(var_t *var, char *val)
{
	if (var->type != ARRAY)
		return (false);
	size_t size = tab_size(var->value.array) + 2;
	var->value.array = my_realloc(var->value.array, sizeof(char *) * size);
	var->value.array[size - 2] = val;
	return (true);
}

static var_t *ini_var_array_create(char *val)
{
	char **array = my_calloc(2, sizeof(char *));
	var_t *var;

	if (!array)
		return (NULL);
	array[0] = val;
	var = var_create(ARRAY, array);
	return (var);
}

bool ini_insert_array(ini_data_t *ini, char *var_name, char *val)
{
	var_t *var;
	size_t len = str_len(var_name) - 2;
	char *varpath;
	bool r = false;

	if (str_empty(ini->var_path))
		varpath = str_ndup(var_name, len);
	else
		my_asprintf(&varpath, "%s:%.*s", ini->var_path, len, var_name);
	if (!varpath)
		return (false);
	var = (var_t *)table_get(ini->vars, varpath);
	if (var)
		r = ini_var_array_append(var, val);
	else {
		var = ini_var_array_create(val);
		r = table_set(ini->vars, varpath, var);
	}
	my_free(varpath);
	return (r);
}
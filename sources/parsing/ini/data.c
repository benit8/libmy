/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** data.c
*/

#include "parsing/ini.h"

static void ini_var_free(void *data)
{
	var_t *var = (var_t *)data;
	var_free(var);
}

ini_data_t *ini_init(void)
{
	ini_data_t *ini = my_calloc(1, sizeof(ini_data_t));

	ini->vars = table_create(&ini_var_free);
	ini->var_path = my_calloc(256, sizeof(char));
	return (ini);
}

void ini_free(ini_data_t *ini)
{
	table_destroy(ini->vars);
	my_free(ini->var_path);
	my_free(ini);
}
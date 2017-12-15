/*
** get.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/parsing/INI
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Dec 12 16:45:49 2017 Benoit Lormeau
** Last update Tue Dec 12 16:45:49 2017 Benoit Lormeau
*/

#include "parsing/ini.h"

int ini_get_integer(ini_data_t *ini, const char *var_name)
{
	var_t	*var;

	if (!table_has_key(ini->vars, var_name)){
		my_dprintf(2, "INI: Key '%s' not found\n", var_name);
		return (0);
	}
	var = (var_t *)table_get(ini->vars, var_name);
	switch (var->type) {
		case INTEGER:
			return (var->value.integer);
		case DECIMAL:
			return ((int)var->value.decimal);
		case STRING:
			return (my_atoi(var->value.string));
		default:
			my_dprintf(2, "INI: '%s': Not an integer\n", var_name);
		break;
	}
	return (0);
}

double ini_get_decimal(ini_data_t *ini, const char *var_name)
{
	var_t	*var;

	if (!table_has_key(ini->vars, var_name)){
		my_dprintf(2, "INI: Key '%s' not found\n", var_name);
		return (0);
	}
	var = (var_t *)table_get(ini->vars, var_name);
	switch (var->type) {
		case INTEGER:
			return ((double)var->value.integer);
		case DECIMAL:
			return (var->value.decimal);
		case STRING:
			return (my_atof(var->value.string));
		default:
			my_dprintf(2, "INI: '%s': Not a decimal\n", var_name);
		break;
	}
	return (0);
}

char *ini_get_string(ini_data_t *ini, const char *var_name)
{
	var_t	*var;

	if (!table_has_key(ini->vars, var_name)){
		my_dprintf(2, "INI: Key '%s' not found\n", var_name);
		return (NULL);
	}
	var = (var_t *)table_get(ini->vars, var_name);
	switch (var->type) {
		// case INTEGER:
		// 	return (my_itoa(var->value.integer));
		// case DECIMAL:
		// 	return (my_ftoa(var->value.decimal, 6));
		case STRING:
			return (var->value.string);
		default:
			my_dprintf(2, "INI: '%s': Not a string\n", var_name);
		break;
	}
	return (NULL);
}

char **ini_get_array(ini_data_t *ini, const char *var_name)
{
	var_t	*var;

	if (!table_has_key(ini->vars, var_name)){
		my_dprintf(2, "INI: Key '%s' not found\n", var_name);
		return (NULL);
	}
	var = (var_t *)table_get(ini->vars, var_name);
	if (var->type == ARRAY)
		return (var->value.array);
	else
		my_dprintf(2, "INI: '%s': Not an array\n", var_name);
	return (NULL);
}
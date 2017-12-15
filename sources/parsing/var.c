/*
** var.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/parsing
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Dec 12 15:46:28 2017 Benoit Lormeau
** Last update Tue Dec 12 15:46:28 2017 Benoit Lormeau
*/

#include "parsing/var.h"

static void var_free_array(char **array)
{
	for (size_t i = 0; array[i] != NULL; ++i)
		my_free(array[i]);
	my_free(array);
}

var_t *var_create(var_type_t type, void *value)
{
	var_t *var = my_calloc(1, sizeof(var_t));

	if (!var)
		return (NULL);
	var->type = type;
	var_set_val(var, type, value);
	return (var);
}

void var_free(var_t *var)
{
	switch (var->type){
		case STRING:
			my_free(var->value.string);
		break;
		case ARRAY:
			var_free_array(var->value.array);
		break;
		case OBJECT:
			table_destroy(var->value.object);
		break;
		case INTEGER:
		case DECIMAL:
		case UNDEFINED:
		default:
		break;
	}
	my_free(var);
}

void var_set_val(var_t *var, var_type_t type, void *value)
{
	switch (type){
		case INTEGER:
			var->value.integer = *(int *)value;
		break;
		case DECIMAL:
			var->value.decimal = *(double *)value;
		break;
		case STRING:
			var->value.string = (char *)value;
		break;
		case ARRAY:
			var->value.array = (char **)value;
		break;
		case OBJECT:
			var->value.object = (table_t *)value;
		break;
		case UNDEFINED:
		default:
		break;
	}
}
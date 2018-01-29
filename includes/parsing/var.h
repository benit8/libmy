/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** var.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include "dsa/table.h"

////////////////////////////////////////////////////////////////////////////////

typedef enum var_type
{
	INTEGER,
	DECIMAL,
	STRING,
	ARRAY,
	OBJECT,
	UNDEFINED
} var_type_t;

typedef union value
{
	int integer;
	double decimal;
	char *string;
	char **array;
	table_t *object;
} value_t;

typedef struct var
{
	var_type_t type;
	value_t value;
} var_t;

////////////////////////////////////////////////////////////////////////////////

var_t *var_create(var_type_t type, void *value);
void var_free(var_t *var);
void var_set_val(var_t *var, var_type_t type, void *value);
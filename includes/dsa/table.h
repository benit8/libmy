/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** table.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdlib.h>

#include "dsa_types.h"
#include "memory.h"
#include "string.h"

////////////////////////////////////////////////////////////////////////////////

#define TABLE_SET(table, key, var)	(table_put(table, key, &(var)))
#define TABLE_GET(table, key, TYPE)	(*((TYPE *)table_get(table, key)))

////////////////////////////////////////////////////////////////////////////////

typedef struct table_node
{
	char *key;
	void *data;
	struct table_node *next;
} table_node_t;

typedef struct table
{
	table_node_t *head;
	void (*clean_up)(void *data);
} table_t;

////////////////////////////////////////////////////////////////////////////////

table_t *table_create(void (*clean_up)(void *data));
void table_destroy(table_t *table);
void table_clear(table_t *table);

bool table_is_empty(table_t *table);
bool table_has_key(table_t *table, const char *key);

void *table_get(table_t *table, const char *key);
size_t table_get_size(table_t *table);
char **table_get_keys(table_t *table);

bool table_set(table_t *table, const char *key, void *data);
void table_unset(table_t *table, const char *key);

void table_foreach(table_t *table, void (*callback)(char *key, void *data));
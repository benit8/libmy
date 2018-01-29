/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** tests.c
*/

#include "dsa/table.h"

bool table_is_empty(table_t *table)
{
	return (table != NULL && table->head == NULL);
}

bool table_has_key(table_t *table, const char *key)
{
	if (!table)
		return (false);
	for (table_node_t *cur = table->head; cur != NULL; cur = cur->next) {
		if (str_cmp(cur->key, key) == 0)
			return (true);
	}
	return (false);
}
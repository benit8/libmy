/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** get.c
*/

#include "dsa/table.h"

void *table_get(table_t *table, const char *key)
{
	if (!table)
		return (NULL);
	for (table_node_t *cur = table->head; cur != NULL; cur = cur->next) {
		if (str_cmp(cur->key, key) == 0)
			return (cur->data);
	}
	return (NULL);
}

char **table_get_keys(table_t *table)
{
	size_t i = 0;
	size_t size;
	char **keys;

	if (!table)
		return (NULL);
	size = table_get_size(table);
	keys = my_calloc(size + 1, sizeof(char *));
	if (!keys)
		return (NULL);
	for (table_node_t *curr = table->head; curr != NULL; curr = curr->next)
		keys[i++] = str_dup(curr->key);
	return (keys);
}

size_t table_get_size(table_t *table)
{
	size_t l = 0;

	if (!table)
		return (0);
	for (table_node_t *curr = table->head; curr != NULL; curr = curr->next)
		++l;
	return (l);
}
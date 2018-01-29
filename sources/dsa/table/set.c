/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** set.c
*/

#include "dsa/table.h"

static bool table_insert_new_node(table_t *table, table_node_t *prev,
				  const char *key, void *data)
{
	table_node_t *node = my_calloc(1, sizeof(table_node_t));

	if (!node)
		return (false);
	node->key = str_dup(key);
	node->data = data;
	node->next = NULL;
	if (table->head == NULL)
		table->head = node;
	else
		prev->next = node;
	return (true);
}

bool table_set(table_t *table, const char *key, void *data)
{
	table_node_t *prev;

	if (!table)
		return (false);
	for (table_node_t *cur = table->head; cur != NULL; cur = cur->next) {
		if (str_cmp(cur->key, key) == 0){
			if (table->clean_up)
				(*table->clean_up)(cur->data);
			cur->data = data;
			return (true);
		}
		prev = cur;
	}
	return (table_insert_new_node(table, prev, key, data));
}

static void table_unset_node(table_t *table,
			     table_node_t *cur,
			     table_node_t *prev)
{
	if (table->clean_up)
		(*table->clean_up)(cur->data);
	if (prev == NULL)
		table->head = cur->next;
	else
		prev->next = cur->next;
	my_free(cur->key);
	my_free(cur);
}

void table_unset(table_t *table, const char *key)
{
	table_node_t *prev = NULL;

	if (!table)
		return;
	for (table_node_t *cur = table->head; cur != NULL; cur = cur->next) {
		if (str_cmp(cur->key, key) == 0){
			table_unset_node(table, cur, prev);
			return;
		}
		prev = cur;
	}
}
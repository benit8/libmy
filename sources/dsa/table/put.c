/*
** put.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Table
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 09:40:32 2017 Benoit Lormeau
** Last update Mon Dec 4 09:40:32 2017 Benoit Lormeau
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

bool table_put(table_t *table, const char *key, void *data)
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

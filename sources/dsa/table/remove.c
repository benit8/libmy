/*
** remove.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Table
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 09:43:30 2017 Benoit Lormeau
** Last update Mon Dec 4 09:43:30 2017 Benoit Lormeau
*/

#include "dsa/table.h"

static void table_remove_node(table_t *table,
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

void table_remove(table_t *table, const char *key)
{
	table_node_t *prev = NULL;

	if (!table)
		return;
	for (table_node_t *cur = table->head; cur != NULL; cur = cur->next) {
		if (str_cmp(cur->key, key) == 0){
			table_remove_node(table, cur, prev);
			return;
		}
		prev = cur;
	}
}
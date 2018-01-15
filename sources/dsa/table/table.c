/*
** table.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Table
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 09:37:06 2017 Benoit Lormeau
** Last update Mon Dec 4 09:37:06 2017 Benoit Lormeau
*/

#include "dsa/table.h"

table_t *table_create(clean_func_t *clean_up)
{
	table_t *table = my_calloc(1, sizeof(table_t));

	if (table) {
		table->head = NULL;
		table->clean_up = clean_up;
	}
	return (table);
}

void table_destroy(table_t *table)
{
	if (!table)
		return;
	table_clear(table);
	my_free(table);
}

void table_clear(table_t *table)
{
	table_node_t *next;

	if (!table)
		return;
	for (table_node_t *curr = table->head; curr != NULL; curr = next) {
		next = curr->next;
		if (table->clean_up)
			(*table->clean_up)(curr->data);
		my_free(curr->key);
		my_free(curr);
	}
	table->head = NULL;
}
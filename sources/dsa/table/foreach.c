/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** foreach.c
*/

#include "dsa/table.h"

void table_foreach(table_t *table, void (*callback)(char *key, void *data))
{
	if (!table)
		return;
	for (table_node_t *cur = table->head; cur != NULL; cur = cur->next) {
		(*callback)(cur->key, cur->data);
	}
}
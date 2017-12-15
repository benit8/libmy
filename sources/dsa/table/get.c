/*
** get.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Table
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 09:43:15 2017 Benoit Lormeau
** Last update Mon Dec 4 09:43:15 2017 Benoit Lormeau
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
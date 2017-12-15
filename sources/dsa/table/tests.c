/*
** tests.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Table
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 09:39:49 2017 Benoit Lormeau
** Last update Mon Dec 4 09:39:49 2017 Benoit Lormeau
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
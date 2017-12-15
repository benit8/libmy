/*
** getKeys.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Table
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Dec 12 14:44:08 2017 Benoit Lormeau
** Last update Tue Dec 12 14:44:08 2017 Benoit Lormeau
*/

#include "dsa/table.h"

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
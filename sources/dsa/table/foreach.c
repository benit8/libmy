/*
** forEach.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Table
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Dec 12 10:47:57 2017 Benoit Lormeau
** Last update Tue Dec 12 10:47:57 2017 Benoit Lormeau
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
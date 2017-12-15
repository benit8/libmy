/*
** getSize.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Table
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 09:40:08 2017 Benoit Lormeau
** Last update Mon Dec 4 09:40:08 2017 Benoit Lormeau
*/

#include "dsa/table.h"

size_t table_get_size(table_t *table)
{
	size_t l = 0;

	if (!table)
		return (0);
	for (table_node_t *curr = table->head; curr != NULL; curr = curr->next)
		++l;
	return (l);
}
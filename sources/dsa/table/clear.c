/*
** clear.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Table
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 09:38:57 2017 Benoit Lormeau
** Last update Mon Dec 4 09:38:57 2017 Benoit Lormeau
*/

#include "dsa/table.h"

void table_clear(table_t *table)
{
	table_node_t *next;

	if (!table)
		return;
	for (table_node_t *curr = table->head; curr != NULL; curr = next){
		next = curr->next;
		if (table->clean_up)
			(*table->clean_up)(curr->data);
		my_free(curr->key);
		my_free(curr);
	}
	table->head = NULL;
}
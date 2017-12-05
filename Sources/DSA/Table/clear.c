/*
** clear.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Table
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 09:38:57 2017 Benoit Lormeau
** Last update Mon Dec 4 09:38:57 2017 Benoit Lormeau
*/

#include "DSA/Table.h"

void Table_clear(Table_t *table)
{
	TableNode_t *next;

	if (!table)
		return;
	for (TableNode_t *curr = table->head; curr != NULL; curr = next){
		next = curr->next;
		if (table->cleanUp)
			(*table->cleanUp)(curr->data);
		my_free(curr->key);
		my_free(curr);
	}
	table->head = NULL;
}
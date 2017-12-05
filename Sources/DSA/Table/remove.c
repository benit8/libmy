/*
** remove.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Table
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 09:43:30 2017 Benoit Lormeau
** Last update Mon Dec 4 09:43:30 2017 Benoit Lormeau
*/

#include "DSA/Table.h"

void Table_remove(Table_t *table, const char *key)
{
	TableNode_t *prev = NULL;

	if (!table)
		return;
	for (TableNode_t *curr = table->head; curr != NULL; curr = curr->next){
		if (str_cmp(curr->key, key) == 0){
			if (table->cleanUp)
				(*table->cleanUp)(curr->data);
			if (prev == NULL)
				table->head = curr->next;
			else
				prev->next = curr->next;
			my_free(curr->key);
			my_free(curr);
			return;
		}
		prev = curr;
	}
}
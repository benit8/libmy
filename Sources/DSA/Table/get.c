/*
** get.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Table
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 09:43:15 2017 Benoit Lormeau
** Last update Mon Dec 4 09:43:15 2017 Benoit Lormeau
*/

#include "DSA/Table.h"

void *Table_get(Table_t *table, const char *key)
{
	if (!table)
		return (NULL);
	for (TableNode_t *curr = table->head; curr != NULL; curr = curr->next){
		if (str_cmp(curr->key, key) == 0)
			return (curr->data);
	}
	return (NULL);
}
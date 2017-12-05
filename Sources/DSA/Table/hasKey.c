/*
** hasKey.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Table
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 09:39:49 2017 Benoit Lormeau
** Last update Mon Dec 4 09:39:49 2017 Benoit Lormeau
*/

#include "DSA/Table.h"

bool Table_hasKey(Table_t *table, const char *key)
{
	if (!table)
		return (false);
	for (TableNode_t *curr = table->head; curr != NULL; curr = curr->next){
		if (str_cmp(curr->key, key) == 0)
			return (true);
	}
	return (false);
}
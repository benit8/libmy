/*
** put.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Table
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 09:40:32 2017 Benoit Lormeau
** Last update Mon Dec 4 09:40:32 2017 Benoit Lormeau
*/

#include "DSA/Table.h"

TableNode_t *new_table_node(const char *key, void *data)
{
	TableNode_t *node = my_calloc(1, sizeof(TableNode_t));

	if (!node){
		node->key = str_dup(key);
		node->data = data;
		node->next = NULL;
	}
	return (node);
}

bool Table_put(Table_t *table, const char *key, void *data)
{
	TableNode_t *prev;
	TableNode_t *new;

	if (!table)
		return (false);
	for (TableNode_t *curr = table->head; curr != NULL; curr = curr->next){
		if (str_cmp(curr->key, key) == 0){
			curr->data = data;
			return (true);
		}
		prev = curr;
	}
	new = new_table_node(key, data);
	if (!new)
		return (false);
	if (table->head == NULL)
		table->head = new;
	else
		prev->next = new;
	return (true);
}
/*
** getSize.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Table
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 09:40:08 2017 Benoit Lormeau
** Last update Mon Dec 4 09:40:08 2017 Benoit Lormeau
*/

#include "DSA/Table.h"

size_t Table_getSize(Table_t *table)
{
	size_t l = 0;

	for (TableNode_t *curr = table->head; curr != NULL; curr = curr->next)
		++l;
	return (l);
}
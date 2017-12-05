/*
** create.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Table
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 09:37:06 2017 Benoit Lormeau
** Last update Mon Dec 4 09:37:06 2017 Benoit Lormeau
*/

#include "DSA/Table.h"

Table_t *Table_create(void (*cleanUp)(void *data))
{
	Table_t *table = my_calloc(1, sizeof(Table_t));

	if (table){
		table->head = NULL;
		table->cleanUp = cleanUp;
	}
	return (table);
}
/*
** create.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Table
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 09:37:06 2017 Benoit Lormeau
** Last update Mon Dec 4 09:37:06 2017 Benoit Lormeau
*/

#include "dsa/table.h"

table_t *table_create(void (*clean_up)(void *data))
{
	table_t *table = my_calloc(1, sizeof(table_t));

	if (table){
		table->head = NULL;
		table->clean_up = clean_up;
	}
	return (table);
}
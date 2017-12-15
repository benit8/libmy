/*
** destroy.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Table
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 09:38:37 2017 Benoit Lormeau
** Last update Mon Dec 4 09:38:37 2017 Benoit Lormeau
*/

#include "dsa/table.h"

void table_destroy(table_t *table)
{
	if (!table)
		return;
	table_clear(table);
	my_free(table);
}
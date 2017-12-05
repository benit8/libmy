/*
** destroy.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Table
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 09:38:37 2017 Benoit Lormeau
** Last update Mon Dec 4 09:38:37 2017 Benoit Lormeau
*/

#include "DSA/Table.h"

void Table_destroy(Table_t *table)
{
	if (!table)
		return;
	Table_clear(table);
	my_free(table);
}
/*
** isEmpty.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Table
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 09:39:18 2017 Benoit Lormeau
** Last update Mon Dec 4 09:39:18 2017 Benoit Lormeau
*/

#include "dsa/table.h"

bool table_is_empty(table_t *table)
{
	return (table != NULL && table->head == NULL);
}
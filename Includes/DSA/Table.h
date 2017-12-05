/*
** Table.h for Libmy in /mnt/data/Delivery/Perso/Libmy/Includes/DSA
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Fri Dec 1 16:29:35 2017 Benoit Lormeau
** Last update Fri Dec 1 16:29:35 2017 Benoit Lormeau
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>

#include "Memory.h"
#include "String.h"

////////////////////////////////////////////////////////////////////////////////

#define TABLE_PUT(table, key, var)	(Table_put(table, key, &(var)))
#define TABLE_GET(table, key, TYPE)	(*((TYPE *)Table_get(table, key)))

////////////////////////////////////////////////////////////////////////////////

typedef struct	TableNode
{
	char			*key;
	void			*data;
	struct TableNode	*next;
}		TableNode_t;

typedef struct	Table
{
	TableNode_t	*head;
	void		(*cleanUp)(void *data);
}		Table_t;

////////////////////////////////////////////////////////////////////////////////

Table_t	*Table_create(void (*cleanUp)(void *data));
void	Table_destroy(Table_t *table);
void	Table_clear(Table_t *table);
bool	Table_isEmpty(Table_t *table);
bool	Table_hasKey(Table_t *table, const char *key);
size_t	Table_getSize(Table_t *table);
bool	Table_put(Table_t *table, const char *key, void *data);
void	*Table_get(Table_t *table, const char *key);
void	Table_remove(Table_t *table, const char *key);
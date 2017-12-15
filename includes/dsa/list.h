/*
** list.h for Libmy in /mnt/data/Delivery/Perso/Libmy/Includes/dsa
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 10:03:10 2017 Benoit Lormeau
** Last update Mon Dec 4 10:03:10 2017 Benoit Lormeau
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdlib.h>

#include "memory.h"

////////////////////////////////////////////////////////////////////////////////

#define LIST_PUSH(list, var)	(list_push(list, &(var)))
#define LIST_POP(list, TYPE)	(*((TYPE *)list_pop(list)))
#define LIST_UNSHIFT(list, var)	(list_unshift(list, &(var)))
#define LIST_SHIFT(list, TYPE)	(*((TYPE *)list_shift(list)))

////////////////////////////////////////////////////////////////////////////////

typedef struct	list_node
{
	void			*data;

	struct list_node	*prev;
	struct list_node	*next;
}		list_node_t;

typedef struct	list
{
	list_node_t	*head;
	list_node_t	*rear;

	void		(*clean_up)(void *data);
}		list_t;

////////////////////////////////////////////////////////////////////////////////

list_t	*list_create(void (*clean_up)(void *data));
void	 list_destroy(list_t *list);
void	 list_clear(list_t *list);
bool	 list_is_empty(list_t *list);
size_t	 list_get_size(list_t *list);
bool	 list_push(list_t *list, void *data);
void	*list_pop(list_t *list);
bool	 list_unshift(list_t *list, void *data);
void	*list_shift(list_t *list);
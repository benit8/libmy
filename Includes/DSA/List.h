/*
** List.h for Libmy in /mnt/data/Delivery/Perso/Libmy/Includes/DSA
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

#include "Memory.h"

////////////////////////////////////////////////////////////////////////////////

#define LIST_PUSH(list, var)	(List_push(list, &(var)))
#define LIST_POP(list, TYPE)	(*((TYPE *)List_pop(list)))
#define LIST_UNSHIFT(list, var)	(List_unshift(list, &(var)))
#define LIST_SHIFT(list, TYPE)	(*((TYPE *)List_shift(list)))

////////////////////////////////////////////////////////////////////////////////

typedef struct	ListNode
{
	void		*data;

	struct ListNode	*prev;
	struct ListNode	*next;
}		ListNode_t;

typedef struct	List
{
	ListNode_t	*head;
	ListNode_t	*rear;

	void		(*cleanUp)(void *data);
}		List_t;

////////////////////////////////////////////////////////////////////////////////

List_t	*List_create(void (*cleanUp)(void *data));
void	List_destroy(List_t *list);
void	List_clear(List_t *list);
bool	List_isEmpty(List_t *list);
size_t	List_getSize(List_t *list);
bool	List_push(List_t *list, void *data);
void	*List_pop(List_t *list);
bool	List_unshift(List_t *list, void *data);
void	*List_shift(List_t *list);
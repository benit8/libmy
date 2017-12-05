/*
** Queue.h for Libmy in /mnt/data/Delivery/Perso/Libmy/Includes/DSA
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:40:40 2017 Benoit Lormeau
** Last update Mon Dec 4 11:40:40 2017 Benoit Lormeau
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdlib.h>

#include "Memory.h"

////////////////////////////////////////////////////////////////////////////////

#define QUEUE_PUSH(queue, var)	(Queue_push(stack, &(var)))
#define QUEUE_POP(queue, TYPE)	(*((TYPE *)Queue_pop(stack)))
#define QUEUE_PEEK(queue, TYPE)	(*((TYPE *)Queue_peek(stack)))

////////////////////////////////////////////////////////////////////////////////

typedef struct	QueueNode
{
	void			*data;
	struct QueueNode	*next;
}		QueueNode_t;

typedef struct	Queue
{
	QueueNode_t	*head;
	void		(*cleanUp)(void *data);
}		Queue_t;

////////////////////////////////////////////////////////////////////////////////

Queue_t	*Queue_create(void (*cleanUp)(void *data));
void	Queue_destroy(Queue_t *queue);
void	Queue_clear(Queue_t *queue);
bool	Queue_isEmpty(Queue_t *queue);
size_t	Queue_getSize(Queue_t *queue);
bool	Queue_push(Queue_t *queue, void *data);
void	*Queue_pop(Queue_t *queue);
void	*Queue_peek(Queue_t *queue);
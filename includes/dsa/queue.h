/*
** queue.h for Libmy in /mnt/data/Delivery/Perso/Libmy/Includes/dsa
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

#include "dsa_types.h"
#include "memory.h"

////////////////////////////////////////////////////////////////////////////////

#define QUEUE_PUSH(queue, var)	(queue_push(stack, &(var)))
#define QUEUE_POP(queue, TYPE)	(*((TYPE *)queue_pop(stack)))
#define QUEUE_PEEK(queue, TYPE)	(*((TYPE *)queue_peek(stack)))

////////////////////////////////////////////////////////////////////////////////

typedef struct queue_node
{
	void *data;
	struct queue_node *next;
} queue_node_t;

typedef struct Queue
{
	queue_node_t *head;
	void (*clean_up)(void *data);
} queue_t;

////////////////////////////////////////////////////////////////////////////////

queue_t *queue_create(void (*clean_up)(void *data));
void queue_destroy(queue_t *queue);
void queue_clear(queue_t *queue);

size_t queue_get_size(queue_t *queue);

bool queue_is_empty(queue_t *queue);

bool queue_push(queue_t *queue, void *data);
void *queue_pop(queue_t *queue);
void *queue_peek(queue_t *queue);
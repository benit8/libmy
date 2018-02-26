/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** queue.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdlib.h>

#include "dsa/dsa_types.h"
#include "dsa/list.h"
#include "memory.h"

////////////////////////////////////////////////////////////////////////////////

#define QUEUE_PUSH(queue, var)	(queue_push(queue, &(var)))
#define QUEUE_POP(queue, TYPE)	(*((TYPE *)queue_pop(queue)))
#define QUEUE_PEEK(queue, TYPE)	(*((TYPE *)queue_peek(queue)))

////////////////////////////////////////////////////////////////////////////////

typedef list_node_t queue_node_t;
typedef list_t queue_t;

////////////////////////////////////////////////////////////////////////////////

queue_t *queue_create(void (*clean_up)(void *data));
void queue_destroy(queue_t *queue);
void queue_clear(queue_t *queue);

bool queue_is_empty(queue_t *queue);
size_t queue_get_size(queue_t *queue);

bool queue_push(queue_t *queue, void *data);
void *queue_pop(queue_t *queue);
void *queue_peek(queue_t *queue);
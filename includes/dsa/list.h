/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** list.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdlib.h>

#include "dsa/dsa_types.h"
#include "memory.h"

////////////////////////////////////////////////////////////////////////////////

#define LIST_PUSH_BACK(list, var)	(list_push_back(list, &(var)))
#define LIST_PUSH_FRONT(list, var)	(list_push_front(list, &(var)))
#define LIST_POP_BACK(list, TYPE)	(*((TYPE *)list_pop_back(list)))
#define LIST_POP_FRONT(list, TYPE)	(*((TYPE *)list_pop_front(list)))
#define LIST_AT(list, at, TYPE)		(*((TYPE *)list_at(list, at)))
#define LIST_BACK(list, TYPE)		(*((TYPE *)list_back(list)))
#define LIST_FRONT(list, TYPE)		(*((TYPE *)list_front(list)))
#define LIST_INSERT(list, pos, var)	(list_insert(list, pos, &(var)))

////////////////////////////////////////////////////////////////////////////////

typedef struct list_node
{
	void *data;

	struct list_node *prev;
	struct list_node *next;
} list_node_t;

typedef struct list
{
	list_node_t *head;
	list_node_t *rear;

	clean_func_t *clean_up;
} list_t;

////////////////////////////////////////////////////////////////////////////////

list_t *list_create(clean_func_t *clean_up;);
void list_destroy(list_t *list);

bool list_is_empty(list_t *list);
size_t list_get_size(list_t *list);

void *list_at(list_t *list, size_t at);
void *list_back(list_t *list);
void *list_front(list_t *list);

bool list_push_back(list_t *list, void *data);
void *list_pop_back(list_t *list);
bool list_push_front(list_t *list, void *data);
void *list_pop_front(list_t *list);
bool list_insert(list_t *list, size_t pos, void *data);
void list_erase(list_t *list, size_t pos);
void list_clear(list_t *list);

void list_foreach(list_t *this, void (*callback)(void *data));
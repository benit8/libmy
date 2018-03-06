/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** stack.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdlib.h>

#include "dsa/dsa_types.h"
#include "dsa/list.h"
#include "memory.h"

////////////////////////////////////////////////////////////////////////////////

#define STACK_PUSH(stack, var)	(stack_push(stack, &(var)))
#define STACK_POP(stack, TYPE)	(*((TYPE *)stack_pop(stack)))
#define STACK_PEEK(stack, TYPE)	(*((TYPE *)stack_peek(stack)))

////////////////////////////////////////////////////////////////////////////////

typedef list_node_t stack_node_t;
typedef list_t stack_t;

////////////////////////////////////////////////////////////////////////////////

stack_t *stack_create(clean_func_t *clean_up;);
void stack_destroy(stack_t *stack);
void stack_clear(stack_t *stack);

bool stack_is_empty(stack_t *stack);
size_t stack_get_size(stack_t *stack);

bool stack_push(stack_t *stack, void *data);
void *stack_pop(stack_t *stack);
void *stack_peek(stack_t *stack);
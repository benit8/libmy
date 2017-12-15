/*
** stack.h for Libmy in /mnt/data/Delivery/Perso/Libmy/Includes/dsa
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 10:55:20 2017 Benoit Lormeau
** Last update Mon Dec 4 10:55:20 2017 Benoit Lormeau
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdlib.h>

#include "memory.h"

////////////////////////////////////////////////////////////////////////////////

#define STACK_PUSH(stack, var)	(stack_push(stack, &(var)))
#define STACK_POP(stack, TYPE)	(*((TYPE *)stack_pop(stack)))
#define STACK_PEEK(stack, TYPE)	(*((TYPE *)stack_peek(stack)))

////////////////////////////////////////////////////////////////////////////////

typedef struct	stack_node
{
	void			*data;
	struct stack_node	*next;
}		stack_node_t;

typedef struct	Stack
{
	stack_node_t	*head;
	void		(*clean_up)(void *data);
}		stack_t;

////////////////////////////////////////////////////////////////////////////////

stack_t	*stack_create(void (*clean_up)(void *data));
void	stack_destroy(stack_t *stack);
void	stack_clear(stack_t *stack);

size_t	stack_get_size(stack_t *stack);

bool	stack_is_empty(stack_t *stack);

bool	stack_push(stack_t *stack, void *data);
void	*stack_pop(stack_t *stack);
void	*stack_peek(stack_t *stack);
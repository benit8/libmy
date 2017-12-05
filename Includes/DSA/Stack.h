/*
** Stack.h for Libmy in /mnt/data/Delivery/Perso/Libmy/Includes/DSA
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

#include "Memory.h"

////////////////////////////////////////////////////////////////////////////////

#define STACK_PUSH(stack, var)	(Stack_push(stack, &(var)))
#define STACK_POP(stack, TYPE)	(*((TYPE *)Stack_pop(stack)))
#define STACK_PEEK(stack, TYPE)	(*((TYPE *)Stack_peek(stack)))

////////////////////////////////////////////////////////////////////////////////

typedef struct	StackNode
{
	void			*data;
	struct StackNode	*next;
}		StackNode_t;

typedef struct	Stack
{
	StackNode_t	*head;
	void		(*cleanUp)(void *data);
}		Stack_t;

////////////////////////////////////////////////////////////////////////////////

Stack_t	*Stack_create(void (*cleanUp)(void *data));
void	Stack_destroy(Stack_t *stack);
void	Stack_clear(Stack_t *stack);
bool	Stack_isEmpty(Stack_t *stack);
size_t	Stack_getSize(Stack_t *stack);
bool	Stack_push(Stack_t *stack, void *data);
void	*Stack_pop(Stack_t *stack);
void	*Stack_peek(Stack_t *stack);
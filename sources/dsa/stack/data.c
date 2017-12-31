/*
** data.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Stack
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:14:05 2017 Benoit Lormeau
** Last update Mon Dec 4 11:14:05 2017 Benoit Lormeau
*/

#include "dsa/stack.h"

bool stack_push(stack_t *stack, void *data)
{
	stack_node_t *node;

	if (!stack)
		return (false);
	node = my_calloc(1, sizeof(stack_node_t));
	if (!node)
		return (false);
	node->data = data;
	node->next = stack->head;
	stack->head = node;
	return (true);
}

void *stack_pop(stack_t *stack)
{
	stack_node_t *first;
	void *data;

	if (!stack || !stack->head)
		return (NULL);
	first = stack->head;
	stack->head = stack->head->next;
	data = first->data;
	my_free(first);
	return (data);
}

void *stack_peek(stack_t *stack)
{
	if (!stack || !stack->head)
		return (NULL);
	return (stack->head->data);
}
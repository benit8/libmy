/*
** pop.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Stack
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:18:55 2017 Benoit Lormeau
** Last update Mon Dec 4 11:18:55 2017 Benoit Lormeau
*/

#include "dsa/stack.h"

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
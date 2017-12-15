/*
** push.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Stack
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
	stack_node_t *new;

	if (!stack)
		return (false);
	new = my_calloc(1, sizeof(stack_node_t));
	if (!new)
		return (false);
	new->data = data;
	new->next = stack->head;
	stack->head = new;
	return (true);
}
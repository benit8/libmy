/*
** stack.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Stack
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:03:08 2017 Benoit Lormeau
** Last update Mon Dec 4 11:03:08 2017 Benoit Lormeau
*/

#include "dsa/stack.h"

stack_t *stack_create(void (*clean_up)(void *data))
{
	stack_t *stack = my_calloc(1, sizeof(stack_t));

	if (stack){
		stack->head = NULL;
		stack->clean_up = clean_up;
	}
	return (stack);
}

void stack_destroy(stack_t *stack)
{
	if (!stack)
		return;
	stack_clear(stack);
	my_free(stack);
}

void stack_clear(stack_t *stack)
{
	stack_node_t *next;

	if (!stack)
		return;
	for (stack_node_t *curr = stack->head; curr != NULL; curr = next){
		next = curr->next;
		if (stack->clean_up)
			(stack->clean_up)(curr->data);
		my_free(curr);
	}
	stack->head = NULL;
}
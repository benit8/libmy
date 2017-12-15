/*
** clear.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Stack
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:10:08 2017 Benoit Lormeau
** Last update Mon Dec 4 11:10:08 2017 Benoit Lormeau
*/

#include "dsa/stack.h"

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
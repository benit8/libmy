/*
** clear.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Stack
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:10:08 2017 Benoit Lormeau
** Last update Mon Dec 4 11:10:08 2017 Benoit Lormeau
*/

#include "DSA/Stack.h"

void Stack_clear(Stack_t *stack)
{
	StackNode_t *next;

	if (!stack)
		return;
	for (StackNode_t *curr = stack->head; curr != NULL; curr = next){
		next = curr->next;
		if (stack->cleanUp)
			(stack->cleanUp)(curr->data);
		my_free(curr);
	}
	stack->head = NULL;
}
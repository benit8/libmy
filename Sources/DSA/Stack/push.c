/*
** push.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Stack
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:14:05 2017 Benoit Lormeau
** Last update Mon Dec 4 11:14:05 2017 Benoit Lormeau
*/

#include "DSA/Stack.h"

bool Stack_push(Stack_t *stack, void *data)
{
	StackNode_t *new;

	if (!stack)
		return (false);
	new = my_calloc(1, sizeof(StackNode_t));
	if (!new)
		return (false);
	new->data = data;
	new->next = stack->head;
	stack->head = new;
	return (true);
}
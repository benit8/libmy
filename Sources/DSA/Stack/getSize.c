/*
** getSize.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Stack
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:13:28 2017 Benoit Lormeau
** Last update Mon Dec 4 11:13:28 2017 Benoit Lormeau
*/

#include "DSA/Stack.h"

size_t Stack_getSize(Stack_t *stack)
{
	size_t l = 0;

	for (StackNode_t *curr = stack->head; curr != NULL; curr = curr->next)
		++l;
	return (l);
}
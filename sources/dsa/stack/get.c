/*
** get.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Stack
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:13:28 2017 Benoit Lormeau
** Last update Mon Dec 4 11:13:28 2017 Benoit Lormeau
*/

#include "dsa/stack.h"

size_t stack_get_size(stack_t *stack)
{
	size_t l = 0;

	for (stack_node_t *curr = stack->head; curr != NULL; curr = curr->next)
		++l;
	return (l);
}
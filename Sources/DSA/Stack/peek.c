/*
** peek.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Stack
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:20:37 2017 Benoit Lormeau
** Last update Mon Dec 4 11:20:37 2017 Benoit Lormeau
*/

#include "DSA/Stack.h"

void *Stack_peek(Stack_t *stack)
{
	if (!stack || !stack->head)
		return (NULL);
	return (stack->head->data);
}
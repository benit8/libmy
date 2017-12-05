/*
** create.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Stack
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:03:08 2017 Benoit Lormeau
** Last update Mon Dec 4 11:03:08 2017 Benoit Lormeau
*/

#include "DSA/Stack.h"

Stack_t *Stack_create(void (*cleanUp)(void *data))
{
	Stack_t *stack = my_calloc(1, sizeof(Stack_t));

	if (stack){
		stack->head = NULL;
		stack->cleanUp = cleanUp;
	}
	return (stack);
}
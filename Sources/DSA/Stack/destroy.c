/*
** destroy.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Stack
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:08:54 2017 Benoit Lormeau
** Last update Mon Dec 4 11:08:54 2017 Benoit Lormeau
*/

#include "DSA/Stack.h"

void Stack_destroy(Stack_t *stack)
{
	if (!stack)
		return;
	Stack_clear(stack);
	my_free(stack);
}
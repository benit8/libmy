/*
** destroy.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Stack
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:08:54 2017 Benoit Lormeau
** Last update Mon Dec 4 11:08:54 2017 Benoit Lormeau
*/

#include "dsa/stack.h"

void stack_destroy(stack_t *stack)
{
	if (!stack)
		return;
	stack_clear(stack);
	my_free(stack);
}
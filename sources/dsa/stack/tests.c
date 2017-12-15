/*
** tests.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Stack
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:11:25 2017 Benoit Lormeau
** Last update Mon Dec 4 11:11:25 2017 Benoit Lormeau
*/

#include "dsa/stack.h"

bool stack_is_empty(stack_t *stack)
{
	return (stack && !stack->head);
}
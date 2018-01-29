/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** stack.c
*/

#include "dsa/stack.h"

stack_t *stack_create(void (*clean_up)(void *data))
{
	return ((stack_t *)list_create(clean_up));
}

void stack_destroy(stack_t *stack)
{
	list_destroy((list_t *)stack);
}
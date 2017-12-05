/*
** isEmpty.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Stack
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:11:25 2017 Benoit Lormeau
** Last update Mon Dec 4 11:11:25 2017 Benoit Lormeau
*/

#include "DSA/Stack.h"

bool Stack_isEmpty(Stack_t *stack)
{
	return (stack && !stack->head);
}
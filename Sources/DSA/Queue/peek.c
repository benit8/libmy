/*
** peek.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Queue
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:45:36 2017 Benoit Lormeau
** Last update Mon Dec 4 11:45:36 2017 Benoit Lormeau
*/

#include "DSA/Queue.h"

void *Queue_peek(Queue_t *queue)
{
	if (!queue || !queue->head)
		return (NULL);
	return (queue->head->data);
}
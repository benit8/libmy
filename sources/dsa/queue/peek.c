/*
** peek.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Queue
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:45:36 2017 Benoit Lormeau
** Last update Mon Dec 4 11:45:36 2017 Benoit Lormeau
*/

#include "dsa/queue.h"

void *queue_peek(queue_t *queue)
{
	if (!queue || !queue->head)
		return (NULL);
	return (queue->head->data);
}
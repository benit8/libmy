/*
** getSize.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Queue
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:45:00 2017 Benoit Lormeau
** Last update Mon Dec 4 11:45:00 2017 Benoit Lormeau
*/

#include "dsa/queue.h"

size_t queue_get_size(queue_t *queue)
{
	size_t l = 0;

	for (queue_node_t *curr = queue->head; curr != NULL; curr = curr->next)
		++l;
	return (l);
}
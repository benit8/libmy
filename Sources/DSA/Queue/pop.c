/*
** pop.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Queue
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:45:41 2017 Benoit Lormeau
** Last update Mon Dec 4 11:45:41 2017 Benoit Lormeau
*/

#include "DSA/Queue.h"

void *Queue_pop(Queue_t *queue)
{
	QueueNode_t *first;
	void *data;

	if (!queue || !queue->head)
		return (NULL);
	first = queue->head;
	queue->head = queue->head->next;
	data = first->data;
	my_free(first);
	return (data);
}
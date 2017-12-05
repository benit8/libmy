/*
** push.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Queue
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:46:28 2017 Benoit Lormeau
** Last update Mon Dec 4 11:46:28 2017 Benoit Lormeau
*/

#include "DSA/Queue.h"

bool Queue_push(Queue_t *queue, void *data)
{
	QueueNode_t *last;
	QueueNode_t *new;

	if (!queue)
		return (false);
	new = my_calloc(1, sizeof(QueueNode_t));
	if (!new)
		return (false);
	new->data = data;
	new->next = NULL;
	if (!queue->head)
		queue->head = new;
	else {
		for (last = queue->head; last->next != NULL; last = last->next);
		last->next = new;
	}
	return (true);
}
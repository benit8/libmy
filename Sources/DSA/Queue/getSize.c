/*
** getSize.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Queue
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:45:00 2017 Benoit Lormeau
** Last update Mon Dec 4 11:45:00 2017 Benoit Lormeau
*/

#include "DSA/Queue.h"

size_t Queue_getSize(Queue_t *queue)
{
	size_t l = 0;

	for (QueueNode_t *curr = queue->head; curr != NULL; curr = curr->next)
		++l;
	return (l);
}
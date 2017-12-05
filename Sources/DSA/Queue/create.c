/*
** create.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Queue
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:41:53 2017 Benoit Lormeau
** Last update Mon Dec 4 11:41:53 2017 Benoit Lormeau
*/

#include "DSA/Queue.h"

Queue_t *Queue_create(void (*cleanUp)(void *data))
{
	Queue_t *queue = my_calloc(1, sizeof(Queue_t));

	if (queue){
		queue->head = NULL;
		queue->cleanUp = cleanUp;
	}
	return (queue);
}
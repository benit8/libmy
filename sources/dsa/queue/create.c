/*
** create.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Queue
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:41:53 2017 Benoit Lormeau
** Last update Mon Dec 4 11:41:53 2017 Benoit Lormeau
*/

#include "dsa/queue.h"

queue_t *queue_create(void (*clean_up)(void *data))
{
	queue_t *queue = my_calloc(1, sizeof(queue_t));

	if (queue){
		queue->head = NULL;
		queue->clean_up = clean_up;
	}
	return (queue);
}
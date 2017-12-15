/*
** destroy.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Queue
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:44:38 2017 Benoit Lormeau
** Last update Mon Dec 4 11:44:38 2017 Benoit Lormeau
*/

#include "dsa/queue.h"

void queue_destroy(queue_t *queue)
{
	if (!queue)
		return;
	queue_clear(queue);
	my_free(queue);
}
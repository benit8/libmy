/*
** isEmpty.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Queue
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:45:20 2017 Benoit Lormeau
** Last update Mon Dec 4 11:45:20 2017 Benoit Lormeau
*/

#include "dsa/queue.h"

bool queue_is_empty(queue_t *queue)
{
	return (queue && !queue->head);
}
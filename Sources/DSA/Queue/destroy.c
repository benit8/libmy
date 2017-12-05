/*
** destroy.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Queue
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:44:38 2017 Benoit Lormeau
** Last update Mon Dec 4 11:44:38 2017 Benoit Lormeau
*/

#include "DSA/Queue.h"

void Queue_destroy(Queue_t *queue)
{
	if (!queue)
		return;
	Queue_clear(queue);
	my_free(queue);
}
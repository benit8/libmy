/*
** isEmpty.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Queue
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:45:20 2017 Benoit Lormeau
** Last update Mon Dec 4 11:45:20 2017 Benoit Lormeau
*/

#include "DSA/Queue.h"

bool Queue_isEmpty(Queue_t *queue)
{
	return (queue && !queue->head);
}
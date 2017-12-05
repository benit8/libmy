/*
** shift.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/List
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 10:25:15 2017 Benoit Lormeau
** Last update Mon Dec 4 10:25:15 2017 Benoit Lormeau
*/

#include "DSA/List.h"

void *List_shift(List_t *list)
{
	ListNode_t *last;
	void *data;

	if (!list || !list->head)
		return (NULL);
	last = list->rear;
	if (!list->head->next)
		list->head = NULL;
	else
		list->rear->prev->next = NULL;
	list->rear = list->rear->prev;
	data = last->data;
	my_free(last);
	return (data);
}
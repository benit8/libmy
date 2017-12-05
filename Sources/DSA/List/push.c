/*
** push.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/List
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 10:17:41 2017 Benoit Lormeau
** Last update Mon Dec 4 10:17:41 2017 Benoit Lormeau
*/

#include "DSA/List.h"

bool List_push(List_t *list, void *data)
{
	ListNode_t *new;

	if (!list)
		return (false);
	new = my_calloc(1, sizeof(ListNode_t));
	if (!new)
		return (false);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	if (!list->head && !list->rear){
		list->head = new;
		list->rear = new;
		return (true);
	}
	new->prev = list->rear;
	list->rear->next = new;
	list->rear = new;
	return (true);
}
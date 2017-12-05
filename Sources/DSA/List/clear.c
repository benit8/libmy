/*
** clear.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/List
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 10:16:34 2017 Benoit Lormeau
** Last update Mon Dec 4 10:16:34 2017 Benoit Lormeau
*/

#include "DSA/List.h"

void List_clear(List_t *list)
{
	ListNode_t *next;

	if (!list)
		return;
	for (ListNode_t *curr = list->head; curr != NULL; curr = next){
		next = curr->next;
		if (list->cleanUp)
			(list->cleanUp)(curr->data);
		my_free(curr);
	}
	list->head = NULL;
	list->rear = NULL;
}
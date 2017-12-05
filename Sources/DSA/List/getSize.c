/*
** getSize.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/List
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 10:17:19 2017 Benoit Lormeau
** Last update Mon Dec 4 10:17:19 2017 Benoit Lormeau
*/

#include "DSA/List.h"

size_t List_getSize(List_t *list)
{
	size_t l = 0;

	for (ListNode_t *curr = list->head; curr != NULL; curr = curr->next)
		++l;
	return (l);
}
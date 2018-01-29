/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** capacity.c
*/

#include "dsa/list.h"

bool list_is_empty(list_t *list)
{
	return (!list->head && !list->rear);
}

size_t list_get_size(list_t *list)
{
	size_t l = 0;

	for (list_node_t *curr = list->head; curr != NULL; curr = curr->next)
		++l;
	return (l);
}
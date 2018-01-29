/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** list.c
*/

#include "dsa/list.h"

list_t *list_create(void (*clean_up)(void *data))
{
	list_t *this = my_calloc(1, sizeof(list_t));

	if (this) {
		this->head = NULL;
		this->rear = NULL;
		this->clean_up = clean_up;
	}
	return (this);
}

void list_destroy(list_t *this)
{
	if (!this)
		return;
	list_clear(this);
	my_free(this);
}
/*
** create.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/List
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 10:10:32 2017 Benoit Lormeau
** Last update Mon Dec 4 10:10:32 2017 Benoit Lormeau
*/

#include "DSA/List.h"

List_t *List_create(void (*cleanUp)(void *data))
{
	List_t *list = my_calloc(1, sizeof(List_t));

	if (list){
		list->head = NULL;
		list->rear = NULL;
		list->cleanUp = cleanUp;
	}
	return (list);
}
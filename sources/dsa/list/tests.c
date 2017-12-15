/*
** tests.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/list
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 10:16:55 2017 Benoit Lormeau
** Last update Mon Dec 4 10:16:55 2017 Benoit Lormeau
*/

#include "dsa/list.h"

bool list_is_empty(list_t *list)
{
	return (!list->head && !list->rear);
}
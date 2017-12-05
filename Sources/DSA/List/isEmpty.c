/*
** isEmpty.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/List
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 10:16:55 2017 Benoit Lormeau
** Last update Mon Dec 4 10:16:55 2017 Benoit Lormeau
*/

#include "DSA/List.h"

bool List_isEmpty(List_t *list)
{
	return (!list->head && !list->rear);
}
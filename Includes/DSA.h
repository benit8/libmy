/*
** DSA.h for Libmy in /mnt/data/Delivery/Perso/Libmy/Includes
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 15:25:38 2017 Benoit Lormeau
** Last update Mon Dec 4 15:25:38 2017 Benoit Lormeau
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include "DSA/List.h"
#include "DSA/Queue.h"
#include "DSA/Stack.h"
#include "DSA/Table.h"

////////////////////////////////////////////////////////////////////////////////

typedef int (cmpFunc_t)(const void *, const void *);

////////////////////////////////////////////////////////////////////////////////

void swap(void *va, void *vb, size_t s);
void sort(void *ptr, size_t n, size_t s, cmpFunc_t *cmp);
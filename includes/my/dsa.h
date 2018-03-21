/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include "my/dsa/list.h"
#include "my/dsa/map.h"
#include "my/dsa/queue.h"
#include "my/dsa/stack.h"

////////////////////////////////////////////////////////////////////////////////

void swap(void *va, void *vb, size_t s);
void sort(void *ptr, size_t n, size_t s, comp_func_t *cmp);
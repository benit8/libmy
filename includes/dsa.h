/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include "dsa/list.h"
#include "dsa/queue.h"
#include "dsa/stack.h"
#include "dsa/table.h"

////////////////////////////////////////////////////////////////////////////////

void swap(void *va, void *vb, size_t s);
void sort(void *ptr, size_t n, size_t s, comp_func_t *cmp);
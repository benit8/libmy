/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** memory.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdint.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////

typedef unsigned char byte_t;

////////////////////////////////////////////////////////////////////////////////

void *my_malloc(size_t size);
void *my_calloc(size_t n, size_t s);
void *my_realloc(void *ptr, size_t newSize);
void my_free(void *ptr);

size_t my_malloc_size(const void *ptr);

int mem_cmp(const void *a, const void *b, size_t n);
void *mem_cpy(void *dest, const void *src, size_t n);
void *mem_dup(const void *src, size_t n);
void *mem_move(void *dest, const void *src, size_t n);
void *mem_set(void *dest, byte_t c, size_t n);
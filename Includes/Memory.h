/*
** Memory.h for libmy in /mnt/data/Delivery/Perso/libmy/Includes
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Thu Nov 9 14:05:48 2017 Benoit Lormeau
** Last update Thu Nov 9 14:05:48 2017 Benoit Lormeau
*/

#pragma once

#include <stdint.h>
#include <stdlib.h>

void	*my_malloc(size_t size);
void	*my_calloc(size_t n, size_t s);
void	*my_realloc(void *ptr, size_t newSize);

void	 my_free(void *ptr);
size_t	 my_malloc_size(const void *ptr);

void	*my_memcpy(void *dest, const void *src, size_t len);
void	*my_memdup(const void *src, size_t size);
void	*my_memset(void *dest, uint8_t c, size_t n);
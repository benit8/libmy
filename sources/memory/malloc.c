/*
** malloc.c for Code in /mnt/data/Delivery/Perso/libmy/Sources/Memory
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Jun 20 17:57:20 2017 Benoit Lormeau
** Last update Tue Jun 20 17:57:20 2017 Benoit Lormeau
*/

#include "memory.h"

void *my_malloc(size_t size)
{
	void *ptr;

	ptr = malloc(sizeof(size_t) + size);
	if (ptr == NULL)
#ifdef ASSERT_MALLOC
		exit(1);
#else
		return (NULL);
#endif
	mem_cpy(ptr, &size, sizeof(size_t));
	ptr += sizeof(size_t);
	return (ptr);
}

void my_free(void *ptr)
{
	if (ptr == NULL)
		return;
	free(ptr - sizeof(size_t));
	ptr = NULL;
}

size_t my_malloc_size(const void *ptr)
{
	size_t *size;

	if (ptr == NULL)
		return (0);
	size = (size_t *)(ptr - sizeof(size_t));
	return (*size);
}
/*
** malloc.c for Code in /home/benito/Dropbox/Code
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Jun 20 17:57:20 2017 Benoit Lormeau
** Last update Tue Jun 20 17:57:20 2017 Benoit Lormeau
*/

#include <stdlib.h>

void	*my_malloc(size_t size)
{
  void	*ptr;

  ptr = malloc(sizeof(size_t) + size);
  if (ptr == NULL)
    return (ptr);
  my_memcpy(ptr, &size, sizeof(size_t));
  ptr += sizeof(size_t);
  return (ptr);
}

void  my_free(void *ptr)
{
  free(ptr - sizeof(size_t));
}

void		*my_realloc(void *ptr, size_t newSize)
{
  size_t	curSize;
  void		*newPtr;

  if (ptr == NULL)
    return (my_malloc(newSize));
  curSize = my_malloc_size(ptr);
  if (newSize <= curSize)
    return (ptr);
  newPtr = my_malloc(newSize);
  my_memcpy(ptr, newPtr, curSize);
  my_free(ptr);
  return (newPtr);
}

size_t		my_malloc_size(void *ptr)
{
  size_t	*size;

  size = (size_t *)(ptr - sizeof(size_t));
  return (*size);
}
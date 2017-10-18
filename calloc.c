/**
 * @function:
 *  calloc: malloc and memset to 0
 *
 * @params:
 *  size: size to allocate
 *
 * @body:
 *  @variables:
 *   p: the allocated pointer
 *   t: a char pointer that will be used to iterate over the allocated area.
 *
 *  First, allocate the pointer of the desired size.
 *  Then check if `malloc` failed.
 *   In that case return a null pointer (or exit the program)
 *  Now "copy" the address of the first byte of `p` to `t`.
 *  Iterate over it and set all of its bytes to '\0'.
 *  Pointer is safe to use.
 *
 * @return:
 *  p: pointer to allocated memory
 */

#include <stdlib.h>

void	*my_calloc(size_t n, size_t s)
{
	size_t size = n * s;
	void *p = my_malloc(size);
	register char *t = p;

	if (p == NULL)
		return (NULL);
	while (size--)
		*t++ = 0;
	return (p);
}
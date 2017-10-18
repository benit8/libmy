/*
** memset.c for memset in /home/benito/Dropbox/Code
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Thu Sep 28 11:44:06 2017 Benoit Lormeau
** Last update Thu Sep 28 11:44:06 2017 Benoit Lormeau
*/

#include <stdlib.h>

void	memset(void *dest, char c, size_t n)
{
	register char *d;

	if (n > 0 && dest != NULL){
		d = dest;
		while (n--)
			*d++ = c;
	}
	return (dest);
}
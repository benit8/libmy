/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** getdelim.c
*/

#include "my/io.h"

static bool my_getdelim_init(char **buf, size_t *bufsiz)
{
	if (*buf == NULL || *bufsiz == 0) {
		*bufsiz = BUFFER_SIZE;
		*buf = my_calloc(*bufsiz, sizeof(char));
		if (*buf == NULL)
			return (false);
	}
	return (true);
}

static bool my_getdelim_extend(char **ptrp, char **eptrp, char **buf,
	size_t *bufsiz)
{
	size_t nbufsiz = *bufsiz * 2;
	ssize_t d = *ptrp - *buf;
	char *nbuf = my_realloc(*buf, nbufsiz);

	if (!nbuf)
		return (false);
	*buf = nbuf;
	*bufsiz = nbufsiz;
	*eptrp = nbuf + nbufsiz;
	*ptrp = nbuf + d;
	return (true);
}

ssize_t my_getdelim(char **buf, size_t *bufsiz, int delimiter, FILE *fp)
{
	char *ptr = NULL;
	char *eptr = NULL;
	int c = 0;

	if (!my_getdelim_init(buf, bufsiz))
		return (-1);
	for (ptr = *buf, eptr = *buf + *bufsiz;;) {
		c = fgetc(fp);
		if (c == -1)
			return ((feof(fp) && ptr != *buf) ? ptr - *buf : -1);
		*ptr++ = c;
		if (c == delimiter) {
			*ptr = '\0';
			return (ptr - *buf);
		}
		if (ptr + 2 >= eptr &&
			!my_getdelim_extend(&ptr, &eptr, buf, bufsiz))
			return (-1);
	}
}

ssize_t my_getline(char **buf, size_t *bufsiz, FILE *fp)
{
	return (my_getdelim(buf, bufsiz, '\n', fp));
}
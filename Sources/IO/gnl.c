/*
** gnl.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/IO
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 13:54:31 2017 Benoit Lormeau
** Last update Wed Oct 25 13:54:32 2017 Benoit Lormeau
*/

#include "libmy.h"

char *gnl(const int fd)
{
	char buff[1];
	char *line = my_calloc(1, sizeof(char));
	int r;

	while (1){
		r = read(fd, buff, 1);
		if (r != 1 || buff[0] == '\n')
			break;
		line = str_napd(line, buff, 1);
	}
	if (r == 1 || line[0] != '\0')
		return (line);
	my_free(line);
	return (NULL);
}
/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** tests / dir
*/

#include "libmy.h"

int main(void)
{
	// dir_t *dp = dir_open(".");

	// if (!dp)
	// 	return 1;

	// dirent_t *ent = NULL;
	// while ((ent = dir_read(dp)) != NULL) {
	// 	printf("[%s]\n", ent->d_name);
	// }

	// dir_close(dp);

	int fd = open(".", O_RDONLY, 0);
	if (fd < 0) {
		perror("open");
		return (1);
	}

	char buff[512]; mem_set(buff, 0, 512);
	if (read(fd, buff, 512) == -1) {
		perror("read");
		return 2;
	}
	write(1, buff, 512);

	return 0;
}
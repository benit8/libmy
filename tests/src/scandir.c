/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** tests / scandir
*/

#include "my/fs.h"
#include "my/io.h"

int filter(const dirent_t *dirent)
{
	return (dirent->d_name[0] != '.');
}

int main(int argc, char const *argv[])
{
	const char *path = (argc > 1) ? argv[1] : ".";
	dirent_t **files = NULL;
	int fileCount = my_scandir(path, &files, filter, my_alphanatcasesort);

	if (fileCount == -1) {
		my_fprintf(stderr, "scandir failed.\n");
		return (1);
	}
	for (int i = 0; i < fileCount; ++i) {
		my_printf("%s\n", files[i]->d_name);
		my_free(files[i]);
	}
	my_free(files);
	return (0);
}
/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** scandir.c
*/

#include "fs.h"

static
void scan_dir_sort(const dirent_t **names, int n, dir_compar_t *comp)
{
	const dirent_t *p = NULL;
	const dirent_t *t = NULL;
	size_t i = 0;
	size_t j = n - 1;

	if (n < 2)
		return;
	p = names[n / 2];
	for (; ; ++i, --j) {
		for (; (*comp)(&names[i], &p) < 0; i++);
		for (; (*comp)(&names[j], &p) > 0; j--);
		if (i >= j)
			break;
		t = names[i];
		names[i] = names[j];
		names[j] = t;
	}
	scan_dir_sort(names, i, comp);
	scan_dir_sort(names + i, n - i, comp);
}

int scan_dir(const char *dirpath, dirent_t ***namelist, dir_filter_t *filter,
	dir_compar_t *compar)
{
	dirent_t **names = NULL;
	dirent_t *entry = NULL;
	DIR *dir = opendir(dirpath);
	int n = 0;

	if (!dir)
		return (-1);
	for (entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
		if (filter && (*filter)(entry) == 0)
			continue;
		names = my_realloc(names, sizeof(dirent_t *) * (n + 2));
		if (!names)
			return (-1);
		names[n++] = mem_dup(entry, sizeof(dirent_t));
	}
	closedir(dir);
	if (n > 1 && compar)
		scan_dir_sort((const dirent_t **)names, n, compar);
	*namelist = names;
	return (n);
}
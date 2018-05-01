/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** scandir.c
*/

#include "my/fs.h"

static void my_scandir_sort(const dirent_t **names, int n, dir_compar_t *comp)
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
	my_scandir_sort(names, i, comp);
	my_scandir_sort(names + i, n - i, comp);
}

static bool my_scandir_append(dirent_t ***namesp, int *np, dirent_t *entry)
{
	dirent_t **nnames;

	nnames = my_realloc(*namesp, sizeof(dirent_t *) * ((*np) + 2));
	if (!nnames)
		return (false);
	nnames[*np] = my_memdup(entry, sizeof(dirent_t));
	if (!nnames[*np])
		return (false);
	*namesp = nnames;
	(*np)++;
	return (true);
}

int my_scandir(const char *dirpath, dirent_t ***namelist, dir_filter_t *filter,
	dir_compar_t *compar)
{
	dirent_t **names = NULL;
	dirent_t *entry = NULL;
	DIR *dir = opendir(dirpath);
	int n = 0;

	if (!dir)
		return (-1);
	while ((entry = readdir(dir)) != NULL) {
		if (filter && (*filter)(entry) == 0)
			continue;
		if (!my_scandir_append(&names, &n, entry))
			break;
	}
	closedir(dir);
	if (n > 1 && compar)
		my_scandir_sort((const dirent_t **)names, n, compar);
	*namelist = names;
	return (n);
}
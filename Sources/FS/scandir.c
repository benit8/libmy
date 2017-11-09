/*
** scandir.c for libmy in /mnt/data/Delivery/Perso/libmy
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 17 16:44:13 2017 Benoit Lormeau
** Last update Tue Oct 17 16:44:13 2017 Benoit Lormeau
*/

#include "FS.h"

static void my_scandir_sort(const dirent_t **names,
                            int n,
                            dirCompar_t *comp)
{
	const dirent_t *p = NULL;
	const dirent_t *t = NULL;
	size_t i = 0;
	size_t j = n - 1;

	if (n < 2)
		return;
	p = names[n / 2];
	for (; ; ++i, --j){
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

int my_scandir(const char *dirpath,
               dirent_t ***namelist,
               dirFilter_t *filter,
               dirCompar_t *compar)
{
	dirent_t **names = NULL;
	dirent_t *entry = NULL;
	DIR *dir = opendir(dirpath);
	int n = 0;

	if (dir == NULL)
		return (-1);
	for (entry = readdir(dir); entry != NULL; entry = readdir(dir)){
		if (filter != NULL && !(*filter)(entry))
			continue;
		names = my_realloc(names, sizeof(dirent_t *) * (n + 2));
		if (names == NULL)
			return (-1);
		names[n++] = my_memdup(entry, sizeof(dirent_t));
	}
	closedir(dir);
	if (n > 1 && compar != NULL)
		my_scandir_sort((const dirent_t **)names, n, compar);
	*namelist = names;
	return (n);
}

int my_alphasort(const dirent_t **a, const dirent_t **b)
{
	return (str_cmp((*a)->d_name, (*b)->d_name));
}

int my_alphacasesort(const dirent_t **a, const dirent_t **b)
{
	return (str_casecmp((*a)->d_name, (*b)->d_name));
}

int my_hiddenfilter(const dirent_t *entry)
{
	return (entry->d_name[0] != '.');
}
/*
** scandir.c for libmy in /mnt/data/Delivery/Perso/libmy
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 17 16:44:13 2017 Benoit Lormeau
** Last update Tue Oct 17 16:44:13 2017 Benoit Lormeau
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

typedef int (direntFilter_t)(struct dirent *);
typedef int (direntCompar_t)(struct dirent **, struct dirent **);

int	comp(struct dirent **a, struct dirent **b)
{
	return (strcmp((*a)->d_name, (*b)->d_name));
}

static struct dirent *dup_dirent(const struct dirent *entry)
{
	struct dirent *dest = calloc(1, sizeof(struct dirent));

	if (dest == NULL)
		return (NULL);
	dest->d_ino = entry->d_ino;
	dest->d_off = entry->d_off;
	dest->d_reclen = entry->d_reclen;
	dest->d_type = entry->d_type;
	strncpy(dest->d_name, entry->d_name, strlen(entry->d_name));
	return (dest);
}

static void	scandir_sort(struct dirent **names, int n, direntCompar_t *comp)
{
	struct dirent *p = NULL;
	struct dirent *t = NULL;
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
	scandir_sort(names, i, comp);
	scandir_sort(names + i, n - i, comp);
}

int	my_scandir(const char *dirpath,
                   struct dirent ***namelist,
                   direntFilter_t *filter,
                   direntCompar_t *compar)
{
	struct dirent **names = NULL;
	struct dirent *entry = NULL;
	DIR *dir = opendir(dirpath);
	int n = 0;

	if (dir == NULL)
		return (-1);
	for (entry = readdir(dir); entry != NULL; entry = readdir(dir)){
		if (filter != NULL && !(*filter)(entry))
			continue;
		names = realloc(names, sizeof(struct dirent *) * (n + 2));
		if (names == NULL)
			return (-1);
		names[n++] = dup_dirent(entry);
	}
	closedir(dir);
	if (n > 1 && compar != NULL)
		scandir_sort(names, n, compar);
	*namelist = names;
	return (n);
}



#include <stdio.h>

int	main(int ac, char **av)
{
	char *dirpath = strdup((ac <= 1) ? "regex/" : av[1]);
	struct dirent **namelist;

	int n = my_scandir(dirpath, &namelist, NULL, comp);
	printf("scandir return: %d\n", n);
	if (n < 0)
		perror("scandir");
	else {
		for (int i = 0; i < n; ++i){
			printf("[%s]\n", namelist[i]->d_name);
			free(namelist[i]);
		}
		free(namelist);
	}

	free(dirpath);
	return (EXIT_SUCCESS);
}
/*
** main.c for libmy in /mnt/data/Delivery/Perso/libmy
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 13:35:15 2017 Benoit Lormeau
** Last update Mon Oct 23 13:35:15 2017 Benoit Lormeau
*/

#include "Libmy.h"
#include "term_colors.h"
#include <stdio.h>

int dirsfirst_sort(dirent_t **a, dirent_t **b)
{
	if (((*a)->d_type == DT_DIR && (*b)->d_type != DT_DIR) ||
	    ((*a)->d_type != DT_DIR && (*b)->d_type == DT_DIR))
		return ((*a)->d_type == DT_DIR ? -1 : 1);
	return (str_casecmp((*a)->d_name, (*b)->d_name));
}

int main(int ac, char **av)
{
	char *dir = (ac < 2) ? "." : av[1];

	dirent_t **files;
	int n = my_scandir(dir, &files, my_hiddenfilter, dirsfirst_sort);

	// Error checking
	if (n == -1){
		perror("my_scandir");
		return (1);
	}

	// Data gathering
	size_t padSize = str_len(dir);
	size_t dirCount = 0;
	size_t fileCount = 0;
	for (int i = 0; i < n; ++i){
		if (files[i]->d_type != DT_DIR)
			fileCount++;
		else {
			dirCount++;
			str_cat(files[i]->d_name, "/");
		}

		padSize = MAX(padSize, str_len(files[i]->d_name));
	}
	padSize += 3;

	// Data display
	char *top = str_repeat("─", padSize - str_len(dir) - 3);
	printf("┌─ %s %s──┐\n", dir, top);
	my_free(top);

	for (int i = 0; i < n; ++i){
		char *padded = str_padr(files[i]->d_name, padSize, " ");

		printf("│ %s │\n", padded);

		my_free(files[i]);
		my_free(padded);
	}

	char *bottom = str_repeat("─", padSize);
	printf("└─%s─┘\n", bottom);
	my_free(bottom);

	printf("\n%lu directories, %lu files\n", dirCount, fileCount);

	// END
	my_free(files);
	return (0);
}

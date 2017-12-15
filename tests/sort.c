/*
** sort.c for libmy tests in /mnt/data/Delivery/Perso/Libmy/Tests
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 15:28:08 2017 Benoit Lormeau
** Last update Mon Dec 4 15:28:08 2017 Benoit Lormeau
*/

#include <stdio.h>
#include <limits.h>
#include "Libmy.h"
#include "term_colors.h"

int cmp(const void *va, const void *vb)
{
	dirent_t *a = *(dirent_t **)va;
	dirent_t *b = *(dirent_t **)vb;
	char *s1 = a->d_name;
	char *s2 = b->d_name;

	return str_natcasecmp(s1, s2);
}

int main(int ac, char **av)
{
	// if (ac < 2){
	// 	fprintf(stderr, "Give a size\n");
	// 	return (1);
	// }

	// int n = my_atoi(av[1]);
	// if (!n)
	// 	return (1);

	// int *a = my_calloc(n, sizeof(int));
	// if (!a)
	// 	return (1);
	// for (int i = 0; i < n; i++)
	// 	a[i] = irand(-1000, 1000);

	dirent_t **a = NULL;
	dirent_t *entry = NULL;
	DIR *dir = opendir("zdoc/");
	int n = 0;

	if (dir == NULL)
		return (1);
	for (entry = readdir(dir); entry != NULL; entry = readdir(dir)){
		a = my_realloc(a, sizeof(dirent_t *) * (n + 2));
		if (a == NULL)
			return (-1);
		a[n++] = mem_dup(entry, sizeof(dirent_t));
	}
	closedir(dir);


	printf("== ORIGINAL =============\n");
	for (int i = 0; i < n; i++)
		printf("[%s] ", a[i]->d_name);
	printf("\n\n");

	sort(a, n, sizeof(dirent_t *), &cmp);

	printf("== SORTED ===============\n");
	for (int i = 0; i < n; i++){
		printf("[%s] ", a[i]->d_name);
		my_free(a[i]);
	}
	printf("\n\n");

	// bool sorted = true;
	// for (int i = 1; i < n; i++){
	// 	if (cmp(&a[i - 1], &a[i]) > 0){
	// 		sorted = false;
	// 		break;
	// 	}
	// }

	// if (sorted)
	// 	printf("=> " GREEN "SORTED" RESET "\n");
	// else
	// 	printf("=> " BG_BLACK RED "!!!!!!!!! NOT SORTED !!!!!!!!!" RESET "\n");

	my_free(a);

	return (0);
}
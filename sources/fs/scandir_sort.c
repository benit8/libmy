/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** scandir_sort.c
*/

#include "my/fs.h"

int my_alphasort(const dirent_t **a, const dirent_t **b)
{
	return (my_strcmp((*a)->d_name, (*b)->d_name));
}

int my_alphacasesort(const dirent_t **a, const dirent_t **b)
{
	return (my_strcasecmp((*a)->d_name, (*b)->d_name));
}

int my_alphanatsort(const dirent_t **a, const dirent_t **b)
{
	return (my_strnatcmp((*a)->d_name, (*b)->d_name));
}

int my_alphanatcasesort(const dirent_t **a, const dirent_t **b)
{
	return (my_strnatcasecmp((*a)->d_name, (*b)->d_name));
}
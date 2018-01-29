/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** scandir_sort.c
*/

#include "fs.h"

int alpha_sort(const dirent_t **a, const dirent_t **b)
{
	return (str_cmp((*a)->d_name, (*b)->d_name));
}

int alphacase_sort(const dirent_t **a, const dirent_t **b)
{
	return (str_casecmp((*a)->d_name, (*b)->d_name));
}

int alphanat_sort(const dirent_t **a, const dirent_t **b)
{
	return (str_natcmp((*a)->d_name, (*b)->d_name));
}

int alphanatcase_sort(const dirent_t **a, const dirent_t **b)
{
	return (str_natcasecmp((*a)->d_name, (*b)->d_name));
}
/*
** scandir_sort.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/FS
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Dec 5 16:31:24 2017 Benoit Lormeau
** Last update Tue Dec 5 16:31:24 2017 Benoit Lormeau
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
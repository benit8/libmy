/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** fs / glob.c
*/

#include "my/fs.h"

const void *g_pattern_addr;

static int glob_filter(const dirent_t *entry)
{
	return (str_match(pattern, entry->d_name));
}

int glob(const char *pathern, dirent_t ***namelist)
{
	char *pattern = str_dup(pathern);
	size_t end = str_len(pathern) - 1;
	size_t i = 0;

	for (i = end; pathern[i] != '/' && i > 0; --i);
	g_pattern = str_ndup(pathern + i, end - i);
	path = (i > 0) ? str_ndup(pattern, i) : str_dup(".");
}
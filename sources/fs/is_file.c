/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_file.c
*/

#include "fs.h"

bool is_file(const char *path)
{
	struct stat buf;

	return (lstat(path, &buf) != -1 && S_ISREG(buf.st_mode));
}

bool is_dir(const char *path)
{
	struct stat buf;

	return (lstat(path, &buf) != -1 && S_ISDIR(buf.st_mode));
}

bool is_link(const char *path)
{
	struct stat buf;

	return (lstat(path, &buf) != -1 && S_ISLNK(buf.st_mode));
}
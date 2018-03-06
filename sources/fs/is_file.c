/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_file.c
*/

#include "fs.h"

bool is_file(const char *filepath)
{
	struct stat buf;

	return (lstat(filepath, &buf) != -1 && S_ISREG(buf.st_mode));
}

bool is_dir(const char *filepath)
{
	struct stat buf;

	return (lstat(filepath, &buf) != -1 && S_ISDIR(buf.st_mode));
}

bool is_link(const char *filepath)
{
	struct stat buf;

	return (lstat(filepath, &buf) != -1 && S_ISLNK(buf.st_mode));
}

bool is_chr(const char *filepath)
{
	struct stat buf;

	return (lstat(filepath, &buf) != -1 && S_ISCHR(buf.st_mode));
}

bool is_blk(const char *filepath)
{
	struct stat buf;

	return (lstat(filepath, &buf) != -1 && S_ISBLK(buf.st_mode));
}
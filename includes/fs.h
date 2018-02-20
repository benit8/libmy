/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** fs.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <dirent.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#include "memory.h"
#include "string.h"

////////////////////////////////////////////////////////////////////////////////

typedef struct dirent dirent_t;
typedef int (dir_filter_t)(const dirent_t *);
typedef int (dir_compar_t)(const dirent_t **, const dirent_t **);

////////////////////////////////////////////////////////////////////////////////

int scan_dir(const char *, dirent_t ***, dir_filter_t *, dir_compar_t *);
int alpha_sort(const dirent_t **a, const dirent_t **b);
int alphacase_sort(const dirent_t **a, const dirent_t **b);
int alphanat_sort(const dirent_t **a, const dirent_t **b);
int alphanatcase_sort(const dirent_t **a, const dirent_t **b);

bool file_is(const char *filepath, const char *mask);
bool is_dir(const char *path);
bool is_file(const char *path);
bool is_link(const char *path);
char *file_get_contents(const char *filepath);
char **file_get_lines(const char *filepath);
bool file_put_contents(const char *filepath, char *contents, bool append);
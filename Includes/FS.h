/*
** FS.h for libmy in /mnt/data/Delivery/Perso/libmy/Includes
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Thu Nov 9 13:52:14 2017 Benoit Lormeau
** Last update Thu Nov 9 13:52:14 2017 Benoit Lormeau
*/

#pragma once

#include <dirent.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "Memory.h"
#include "String.h"

typedef struct dirent dirent_t;
typedef int (dirFilter_t)(const dirent_t *);
typedef int (dirCompar_t)(const dirent_t **, const dirent_t **);

int	my_scandir(const char *, dirent_t ***, dirFilter_t *, dirCompar_t *);
int	my_alphasort(const dirent_t **a, const dirent_t **b);
int	my_alphacasesort(const dirent_t **a, const dirent_t **b);
int	my_hiddenfilter(const dirent_t *entry);

bool	  file_is(const char *filepath, const char *mask);
char	 *file_get_contents(const char *filepath);
char	**file_get_lines(const char *filepath);
bool	  file_put_contents(const char *filepath, char *contents);
/*
** regex.h for libmy in /mnt/data/Delivery/Perso/libmy/Includes
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Thu Nov 9 14:07:36 2017 Benoit Lormeau
** Last update Thu Nov 9 14:07:36 2017 Benoit Lormeau
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <regex.h>
#include <stdlib.h>

#include "memory.h"
#include "string.h"

////////////////////////////////////////////////////////////////////////////////

int	  regex_match(const char *pattern, char *subject);
char	 *regex_replace(const char *pattern, const char *repl, char *subject);
char	**regex_capture(const char *pattern, char *subject);
char	**regex_split(char *pattern, char *subject);
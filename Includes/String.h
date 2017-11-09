/*
** String.h for libmy in /mnt/data/Delivery/Perso/libmy/Includes
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Thu Nov 9 14:08:22 2017 Benoit Lormeau
** Last update Thu Nov 9 14:08:22 2017 Benoit Lormeau
*/

#pragma once

#include <stdbool.h>
#include <stdlib.h>

#include "Char.h"
#include "Math.h"
#include "Memory.h"

char	**explode(const char *delim, char *string);
char	 *implode(const char *glue, char **array);
char	 *str_apd(char *dest, const char *src);
int	  str_casecmp(const char *s1, const char *s2);
char	 *str_cat(char *dest, const char *src);
char	 *str_chr(const char *string, char search);
int	  str_cmp(const char *s1, const char *s2);
char	 *str_cpy(char *dest, const char *src);
char	 *str_dup(const char *src);
bool	  str_empty(const char *string);
size_t	  str_len(const char *string);
char	 *str_napd(char *dest, const char *src, size_t n);
int	  str_ncasecmp(const char *s1, const char *s2, size_t n);
char	 *str_ncat(char *dest, const char *src, size_t n);
char	 *str_ncpy(char *dest, const char *src, size_t n);
int	  str_ncmp(const char *s1, const char *s2, size_t n);
char	 *str_ndup(const char *src, size_t n);
size_t	  str_nlen(const char *string, size_t max);
char	 *str_pad(const char *string, size_t padLen, const char *pad);
char	 *str_padl(const char *string, size_t padLen, const char *pad);
char	 *str_padr(const char *string, size_t padLen, const char *pad);
ssize_t	  str_pos(char *string, const char *search);
char	 *str_rchr(const char *string, char search);
char	 *str_repeat(char *string, size_t times);
char	 *str_replace(const char *search, const char *replace, char *subject);
char	 *str_rev(char *string);
char	 *str_sep(char **stringp, const char *delim);
char	 *str_str(char *string, const char *search);
char	 *str_tolower(char *string);
char	 *str_toupper(char *string);
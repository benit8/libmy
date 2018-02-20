/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** string.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdlib.h>

#include "char.h"
#include "math.h"
#include "memory.h"
#include "numeric.h"

////////////////////////////////////////////////////////////////////////////////

char **explode(char *string, const char *delim);
char *implode(char **array, const char *glue);

char *str_apd(char *dest, const char *src);
char *str_napd(char *dest, const char *src, size_t n);
char *str_ppd(char *dest, const char *src);
char *str_nppd(char *dest, const char *src, size_t n);

int str_cmp(const char *s1, const char *s2);
int str_ncmp(const char *s1, const char *s2, size_t n);
int str_casecmp(const char *s1, const char *s2);
int str_ncasecmp(const char *s1, const char *s2, size_t n);
int str_natcasecmp(const char *s1, const char *s2);
int str_nnatcasecmp(const char *s1, const char *s2, size_t n);
int str_natcmp(const char *s1, const char *s2);
int str_nnatcmp(const char *s1, const char *s2, size_t n);

char *str_cat(char *dest, const char *src);
char *str_ncat(char *dest, const char *src, size_t n);

char *str_chr(const char *string, char search);
char *str_nchr(const char *string, char search, size_t n);
char *str_rchr(const char *string, char search);

char *str_cpy(char *dest, const char *src);
char *str_ncpy(char *dest, const char *src, size_t n);

size_t str_spn(const char *str1, const char *str2);
size_t str_cspn(const char *str1, const char *str2);

char *str_dup(const char *src);
char *str_ndup(const char *src, size_t n);

bool str_empty(const char *string);

size_t str_len(const char *string);
size_t str_nlen(const char *string, size_t max);

bool str_match(const char *s1, const char *s2);

ssize_t str_pos(char *string, const char *search);
ssize_t str_npos(char *string, const char *search, size_t n);

char *str_pad(const char *string, size_t padLen, const char *pad);
char *str_padl(const char *string, size_t padLen, const char *pad);
char *str_padr(const char *string, size_t padLen, const char *pad);

char *str_repeat(char *string, size_t times);
char *str_replace(const char *search, const char *replace, char *subject);
char *str_rev(char *string);

char *str_sep(char **stringp, const char *delim);

char *str_str(char *string, const char *search);
char *str_nstr(char *string, const char *search, size_t n);

char *str_tolower(char *string);
char *str_toupper(char *string);

char *str_trim(char *str);
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

#include "my/char.h"
#include "my/math.h"
#include "my/memory.h"
#include "my/numeric.h"

////////////////////////////////////////////////////////////////////////////////

char **explode(char *string, const char *delim);
char *implode(char **array, const char *glue);

char *my_strapd(char *dest, const char *src);
char *my_strnapd(char *dest, const char *src, size_t n);
char *my_strppd(char *dest, const char *src);
char *my_strnppd(char *dest, const char *src, size_t n);

int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, size_t n);
int my_strcasecmp(const char *s1, const char *s2);
int my_strncasecmp(const char *s1, const char *s2, size_t n);
int my_strnatcasecmp(const char *s1, const char *s2);
int my_strnnatcasecmp(const char *s1, const char *s2, size_t n);
int my_strnatcmp(const char *s1, const char *s2);
int my_strnnatcmp(const char *s1, const char *s2, size_t n);

char *my_strcat(char *dest, const char *src);
char *my_strncat(char *dest, const char *src, size_t n);

char *my_strchr(const char *string, char search);
char *my_strnchr(const char *string, char search, size_t n);
char *my_strrchr(const char *string, char search);

char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, size_t n);

size_t my_strspn(const char *str1, const char *str2);
size_t my_strcspn(const char *str1, const char *str2);

char *my_strdup(const char *src);
char *my_strndup(const char *src, size_t n);

bool my_strempty(const char *string);

size_t my_strlen(const char *string);
size_t my_strnlen(const char *string, size_t max);

bool my_strmatch(const char *s1, const char *s2);

ssize_t my_strpos(char *string, const char *search);
ssize_t my_strnpos(char *string, const char *search, size_t n);

char *my_strpad(const char *string, const char *pad, size_t padlen);
char *my_strpadl(const char *string, const char *pad, size_t padlen);
char *my_strpadr(const char *string, const char *pad, size_t padlen);

char *my_strrepeat(char *string, size_t times);
char *my_strreplace(char *subject, const char *search, const char *replace);
char *my_strrev(char *string);

char *my_strsep(char **stringp, const char *delim);

char *my_strstr(char *string, const char *search);
char *my_strnstr(char *string, const char *search, size_t n);

char *my_strtolower(char *string);
char *my_strtoupper(char *string);

char *my_strtrim(char *str);
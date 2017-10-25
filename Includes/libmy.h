/*
** libmy.h for libmy in /mnt/data/Delivery/Perso/libmy
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 09:27:22 2017 Benoit Lormeau
** Last update Tue Oct 24 11:29:18 2017 Benoit Lormeau
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////
/// INCLUDES
////////////////////////////////////////////////////////////////////////////////

#include <dirent.h>
#include <fcntl.h>
#include <regex.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////
/// CHAR
////////////////////////////////////////////////////////////////////////////////

bool is_alnum(int c);
bool is_alpha(int c);
bool is_cntrl(int c);
bool is_digit(int c);
bool is_graph(int c);
bool is_lower(int c);
bool is_print(int c);
bool is_punct(int c);
bool is_space(int c);
bool is_upper(int c);
bool is_xdigit(int c);

int to_lower(int c);
int to_upper(int c);

////////////////////////////////////////////////////////////////////////////////
/// FS
////////////////////////////////////////////////////////////////////////////////

typedef struct dirent dirent_t;
typedef int (direntFilter_t)(dirent_t *);
typedef int (direntCompar_t)(dirent_t **, dirent_t **);

int my_alphasort(dirent_t **a, dirent_t **b);
int my_alphacasesort(dirent_t **a, dirent_t **b);

int my_scandir(const char *, dirent_t ***, direntFilter_t *, direntCompar_t *);

bool file_exists(const char *filepath);
bool file_readable(const char *filepath);
bool file_writable(const char *filepath);
bool file_executable(const char *filepath);

char *file_get_contents(const char *filepath);
bool file_put_contents(const char *filepath, char *buffer);

////////////////////////////////////////////////////////////////////////////////
/// IO
////////////////////////////////////////////////////////////////////////////////

void my_putchar(char c);
void my_putstr(const char *str);
void my_putnbr(int nb);
void my_puts(const char *str);

////////////////////////////////////////////////////////////////////////////////
/// MEMORY
////////////////////////////////////////////////////////////////////////////////

void *my_malloc(size_t size);
void *my_calloc(size_t n, size_t s);
void *my_realloc(void *ptr, size_t newSize);

void my_free(void *ptr);
size_t my_malloc_size(const void *ptr);

void *my_memcpy(void *dest, const void *src, size_t len);
void *my_memdup(const void *src, size_t size);
void *my_memset(void *dest, uint8_t c, size_t n);

////////////////////////////////////////////////////////////////////////////////
/// NUMERIC
////////////////////////////////////////////////////////////////////////////////

int my_abs(int n);

size_t intlen(ssize_t n);
size_t uintlen(size_t n);

ssize_t my_atoi(const char *str);
size_t my_atou(const char *str);
char *my_itoa(ssize_t n);
char *my_utoa(size_t n);

////////////////////////////////////////////////////////////////////////////////
/// REGEX
////////////////////////////////////////////////////////////////////////////////

char **regex_capture(const char *pattern, char *subject);
int regex_match(const char *pattern, char *subject);
char *regex_replace(const char *pattern, const char *replace, char *subject);
char **regex_split(char *pattern, char *subject);

////////////////////////////////////////////////////////////////////////////////
/// STRING
////////////////////////////////////////////////////////////////////////////////

size_t my_strlen(const char *str);
size_t my_strnlen(const char *str, size_t max);

char *my_strapd(char *dest, const char *src);
char *my_strnapd(char *dest, const char *src, size_t n);

char *my_strcat(char *dest, const char *src);
char *my_strncat(char *dest, const char *src, size_t n);

int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, size_t n);

int my_strcasecmp(const char *s1, const char *s2);
int my_strncasecmp(const char *s1, const char *s2, size_t n);

char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, size_t n);

char *my_strdup(const char *src);
char *my_strrev(char *str);
char *my_strstr(char *str, const char *search);
char *my_strsep(char **stringp, const char *delim);

char **explode(const char *delim, char *string);
char *implode(const char *glue, char **array);
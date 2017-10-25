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
bool is_blank(int c);
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

bool file_executable(const char *filepath);
bool file_exists(const char *filepath);
bool file_put_contents(const char *filepath, char *contents);
bool file_readable(const char *filepath);
bool file_writable(const char *filepath);
char **file(const char *filepath);
char *file_get_contents(const char *filepath);

////////////////////////////////////////////////////////////////////////////////
/// IO
////////////////////////////////////////////////////////////////////////////////

char *gnl(const int fd);

void my_putchar(char c);
void my_putstr(const char *str);
void my_putnbr(int nb);
void my_puts(const char *str);

////////////////////////////////////////////////////////////////////////////////
/// MATH
////////////////////////////////////////////////////////////////////////////////

ssize_t my_max(ssize_t a, ssize_t b);
ssize_t my_min(ssize_t a, ssize_t b);

size_t my_umax(size_t a, size_t b);
size_t my_umin(size_t a, size_t b);

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

ssize_t str_to_int(const char *str);
size_t str_to_uint(const char *str);
char *int_to_str(ssize_t n);
char *uint_to_str(size_t n);

////////////////////////////////////////////////////////////////////////////////
/// REGEX
////////////////////////////////////////////////////////////////////////////////

char **regex_capture(const char *pattern, char *subject);
char **regex_split(char *pattern, char *subject);
char *regex_replace(const char *pattern, const char *replace, char *subject);
int regex_match(const char *pattern, char *subject);

////////////////////////////////////////////////////////////////////////////////
/// STRING
////////////////////////////////////////////////////////////////////////////////

bool str_empty(const char *string);
char **explode(const char *delim, char *string);
char *implode(const char *glue, char **array);
char *str_apd(char *dest, const char *src);
char *str_cat(char *dest, const char *src);
char *str_cpy(char *dest, const char *src);
char *str_dup(const char *src);
char *str_napd(char *dest, const char *src, size_t n);
char *str_ncat(char *dest, const char *src, size_t n);
char *str_ncpy(char *dest, const char *src, size_t n);
char *str_ndup(const char *src, size_t n);
char *str_pad(char *string, size_t padLen, char *pad);
char *str_padl(char *string, size_t padLen, char *pad);
char *str_padr(char *string, size_t padLen, char *pad);
char *str_repeat(char *string, size_t times);
char *str_replace(const char *search, const char *replace, char *subject);
char *str_rev(char *string);
char *str_sep(char **stringp, const char *delim);
char *str_str(char *string, const char *search);
int str_casecmp(const char *s1, const char *s2);
int str_cmp(const char *s1, const char *s2);
int str_ncasecmp(const char *s1, const char *s2, size_t n);
int str_ncmp(const char *s1, const char *s2, size_t n);
size_t str_len(const char *string);
size_t str_nlen(const char *string, size_t max);
size_t str_pos(char *string, const char *search);
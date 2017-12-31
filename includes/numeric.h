/*
** numeric.h for libmy in /mnt/data/Delivery/Perso/libmy/Includes
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Thu Nov 9 14:06:55 2017 Benoit Lormeau
** Last update Mon Nov 13 10:44:46 2017 Benoit Lormeau
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>

#include "char.h"
#include "math.h"
#include "memory.h"
#include "string.h"

////////////////////////////////////////////////////////////////////////////////

size_t intlen(ssize_t n);
size_t uintlen(size_t n);

ssize_t my_atoi(const char *str);
size_t my_atou(const char *str);
double my_atof(const char *str);
char *my_itoa(ssize_t n, uint8_t base);
char *my_utoa(size_t n, uint8_t base);
char *my_ftoa(double d, int prec);

long int my_strtol(const char *nptr, char **endptr, int base);
long long int my_strtoll(const char *nptr, char **endptr, int base);
unsigned long int my_strtoul(const char *nptr, char **endptr, int base);
unsigned long long int my_strtoull(const char *nptr, char **endptr, int base);
/*
** Math.h for libmy in /mnt/data/Delivery/Perso/libmy/Includes
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Thu Nov 9 13:54:10 2017 Benoit Lormeau
** Last update Mon Nov 13 14:38:28 2017 Benoit Lormeau
*/

#pragma once

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

////////////////////////////////////////////////////////////////////////////////

#define PI	(3.14159265358979323846f)

////////////////////////////////////////////////////////////////////////////////

#ifndef ABS
	#define ABS(a)		(((a) < 0) ? -(a) : (a))
#endif

#ifndef MIN
	#define MIN(a,b)	(((a) < (b)) ? (a) : (b))
#endif

#ifndef MAX
	#define MAX(a,b)	(((a) > (b)) ? (a) : (b))
#endif

#ifndef CONSTRAIN
	#define CONSTRAIN(v,a,b)	(MAX(a, MIN(v, b)))
#endif

#ifndef IN_RANGE
	#define IN_RANGE(n,a,b)	((n) >= (a) && (n) <= (b))
#endif

#ifndef MAP
	#define MAP(v,a,b,c,d)	((((v) - (a)) / ((b) - (a))) * ((d) - (c)) + (c))
#endif

////////////////////////////////////////////////////////////////////////////////

double	radians(double degrees);
double	degrees(double radians);

void	my_srand(unsigned int seed);
int	rand(void);
int	irand(int a, int b);
double	frand(double a, double b);

double	my_pow(double n, int exp);

double	my_floor(double n);
double	my_floorp(double n, int prec);

double	my_round(double n);
double	my_roundp(double n, int prec);

double	my_ceil(double n);
double	my_ceilp(double n, int prec);
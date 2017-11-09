/*
** Math.h for libmy in /mnt/data/Delivery/Perso/libmy/Includes
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Thu Nov 9 13:54:10 2017 Benoit Lormeau
** Last update Thu Nov 9 13:54:10 2017 Benoit Lormeau
*/

#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#ifndef PI
# define PI	3.14159265358979323846
#endif

#ifndef ABS
# define ABS(a)		(((a) < 0) ? -(a) : (a))
#endif

#ifndef MIN
# define MIN(a, b)	(((a) < (b)) ? (a) : (b))
#endif

#ifndef MAX
# define MAX(a, b)	(((a) > (b)) ? (a) : (b))
#endif

#ifndef CONSTRAIN
# define CONSTRAIN(v, a, b)	((v) < (a) ? (a) : ((v) > (b) ? (b) : (v)))
#endif

#ifndef MAP
# define MAP(v, a, b, c, d)	((((v) - (a)) / ((b) - (a))) * ((d) - (c)) + (c))
#endif

double	radians(double degrees);
double	degrees(double radians);

int	irand(int a, int b);
float	frand(float a, float b);
double	drand(double a, double b);
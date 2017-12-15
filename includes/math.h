/*
** math.h for libmy in /mnt/data/Delivery/Perso/libmy/Includes
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Thu Nov 9 13:54:10 2017 Benoit Lormeau
** Last update Mon Nov 13 14:38:28 2017 Benoit Lormeau
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

////////////////////////////////////////////////////////////////////////////////

#define PI			(3.14159265358979323846)

#define FLOAT_BIAS		127
#define FLOAT_EMASK		2139095040
#define FLOAT_MBITS		23
#define FLOAT_MMASK		8388607
#define FLOAT_EZERO		1065353216

#define DOUBLE_BIAS		1023
#define DOUBLE_EMASK		2146435072
#define DOUBLE_MBITS		20
#define DOUBLE_MMASK		1048575
#define DOUBLE_EZERO		1072693248
#define DOUBLE_EXP_INFNAN	2047

#define FLOAT_LOG2OFE		1.4426950408889634074f
#define FLOAT_LOGEOF2		6.9314718055994530942e-1f
#define FLOAT_LOG2OF10		3.32192809488736234789f
#define FLOAT_LOG10OF2		3.0102999566398119521e-1f
#define FLOAT_LOG10OFE		4.3429448190325182765e-1f
#define FLOAT_SQRT2		1.41421356237309504880f
#define FLOAT_SQRTH		0.70710678118654752440f

#define DOUBLE_LOG2OFE		1.4426950408889634074
#define DOUBLE_LOGEOF2		6.9314718055994530942e-1
#define DOUBLE_LOG2OF10		3.32192809488736234789
#define DOUBLE_LOG10OF2		3.0102999566398119521e-1
#define DOUBLE_LOG10OFE		4.3429448190325182765e-1
#define DOUBLE_SQRT2		1.41421356237309504880
#define DOUBLE_SQRTH		0.70710678118654752440

#define EXP2_Q0			2.33184211722314911771e2
#define EXP2_Q1			4.36821166879210612817e3
#define EXP2_P0			2.30933477057345225087e-2
#define EXP2_P1			2.02020656693165307700e1
#define EXP2_P2			1.51390680115615096133e3

#define LOG_LN2H		6.93147180369123816490e-01
#define LOG_LN2L		1.90821492927058770002e-10
#define LOG_1			6.666666666666735130e-01
#define LOG_2			3.999999999940941908e-01
#define LOG_3			2.857142874366239149e-01
#define LOG_4			2.222219843214978396e-01
#define LOG_5			1.818357216161805012e-01
#define LOG_6			1.531383769920937332e-01
#define LOG_7			1.479819860511658591e-01

////////////////////////////////////////////////////////////////////////////////

#ifndef ABS
	#define ABS(a)			(((a) < 0) ? -(a) : (a))
#endif

#ifndef MIN
	#define MIN(a, b)		(((a) < (b)) ? (a) : (b))
#endif

#ifndef MAX
	#define MAX(a, b)		(((a) > (b)) ? (a) : (b))
#endif

#ifndef CONSTRAIN
	#define CONSTRAIN(v, a, b)	(MAX(a, MIN(v, b)))
#endif

#ifndef IN_RANGE
	#define IN_RANGE(n, a, b)	((n) >= (a) && (n) <= (b))
#endif

#ifndef MAP
	#define MAP(v,a,b,c,d)		(((v - a) / (b - a)) * (d - c) + c)
#endif

////////////////////////////////////////////////////////////////////////////////

typedef union
{
	float		f;
	uint32_t	u;
	int32_t		i;
}		ufi_t;

struct	i2_s
{
	int32_t	i0;
	int32_t	i1;
};

typedef union
{
	double		f;
	uint64_t	u;
	struct i2_s	s;
}		udi_t;

struct	ieee_double
{
	uint32_t	dbl_mantissa2;
	uint32_t	dbl_mantissa1:20;
	uint32_t	dbl_exp:11;
	uint32_t	dbl_sign:1;
};

union	frexp_u
{
	double v;
	struct ieee_double s;
};

////////////////////////////////////////////////////////////////////////////////

double	radians(double degrees);
double	degrees(double radians);

void	my_srand(unsigned int seed);
int	rand(void);
int	irand(int a, int b);
double	frand(double a, double b);

double	my_floor(double n);
double	my_floorp(double n, int prec);

double	my_round(double n);
double	my_roundp(double n, int prec);

double	my_ceil(double n);
double	my_ceilp(double n, int prec);

double	my_pow(double n, double exp);
double	my_log(double x);
double	my_exp(double x);
double	my_exp2(double x);
double	my_exp10(double x);

double	my_fmod(double a, double b);
double	my_frexp(double value, int *eptr);
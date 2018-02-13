/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** rand.c
*/

#include "math.h"

static size_t next = 1;

static
void rand_init(void)
{
	static bool init = false;

	if (init == true)
		return;
	my_srand(time(NULL));
	init = true;
}

////////////////////////////////////////////////////////////////////////////////

void my_srand(unsigned int seed)
{
	next = seed;
}

int my_rand(void)
{
	rand_init();
	next = next * 1103515245 + 12345;
	return (next / UINT_MAX) % INT_MAX;
}

int irand(int a, int b)
{
	return (my_rand() % (b - a) + a);
}

double frand(double a, double b)
{
	return ((my_rand() / (double)RAND_MAX) * (b - a) + a);
}
/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** rand.c
*/

#include "math.h"

static
size_t *rand_get_next(void)
{
	static size_t next = 1;

	return (&next);
}

void my_srand(unsigned int seed)
{
	size_t *nextp = rand_get_next();

	*nextp = seed;
}

int my_rand(void)
{
	static bool init = false;
	size_t *nextp;

	if (!init) {
		my_srand(time(NULL));
		init = true;
	}
	nextp = rand_get_next();
	*nextp = (*nextp) * 1103515245 + 12345;
	return ((*nextp) / UINT_MAX) % INT_MAX;
}

int irand(int a, int b)
{
	return (my_rand() % (b - a) + a);
}

double frand(double a, double b)
{
	return ((my_rand() / (double)RAND_MAX) * (b - a) + a);
}
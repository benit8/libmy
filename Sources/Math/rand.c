/*
** rand.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Math
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 30 10:18:02 2017 Benoit Lormeau
** Last update Mon Oct 30 10:18:02 2017 Benoit Lormeau
*/

#include "Math.h"

static void rand_init(void)
{
	static bool init;

	if (init == true)
		return;
	srand(time(NULL));
	init = true;
}

int irand(int a, int b)
{
	rand_init();
	return (rand() % (b - a) + a);
}

float frand(float a, float b)
{
	rand_init();
	return ((rand() / (float)RAND_MAX) * (b - a) + a);
}

double drand(double a, double b)
{
	rand_init();
	return ((rand() / (double)RAND_MAX) * (b - a) + a);
}
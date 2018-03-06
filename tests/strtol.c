/*
** strtol.c for libmy tests in /mnt/data/Delivery/Perso/Libmy/Tests
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Dec 5 14:21:31 2017 Benoit Lormeau
** Last update Tue Dec 5 14:21:31 2017 Benoit Lormeau
*/

#include <stdio.h>
#include "Libmy.h"

int main(int argc, char **argv)
{
	if (argc < 2)
		return (1);

	char *nptr = argv[1];
	char *endptr = NULL;
	long int n = 0;
	int base = (argc == 3) ? my_atoi(argv[2]) : 0;

	n = my_strtol(nptr, &endptr, base);

	printf("n:      (%ld)\n", n);
	printf("nptr:   '%s'\n", nptr);
	printf("endptr: '%s'\n", endptr);

	return (0);
}
/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** tests / net
*/

#include "libmy.h"

int main(void)
{
	char *s = net_lookup("benito.io");

	printf("[%s]\n", s);
	my_free(s);
	return (0);
}
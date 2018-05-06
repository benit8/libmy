/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** regex / create.c
*/

#include "my/regex.h"

bool regex_create(regex_t *regex, const char *pattern)
{
	char errbuff[256];
	int code = regcomp(regex, pattern, REG_EXTENDED);

	if (code == 0)
		return (true);
	my_memset(errbuff, 0, sizeof(errbuff));
	regerror(code, regex, errbuff, sizeof(errbuff));
	my_fprintf(stderr, "regcomp() failed: %s\n", errbuff);
	return (false);
}
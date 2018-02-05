/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** match.c
*/

#include "cregex.h"

int regex_match(const char *pattern, char *subject)
{
	regex_t regex;
	regmatch_t *matches = my_calloc(1, sizeof(regmatch_t));
	int ok = regcomp(&regex, pattern, REG_EXTENDED);
	int n = 0;

	if (ok != 0 || matches == NULL)
		return (-1);
	for (n = 0; regexec(&regex, subject, 1, matches, 0) != REG_NOMATCH; ++n)
		subject += matches[0].rm_eo;
	regfree(&regex);
	my_free(matches);
	return (n);
}
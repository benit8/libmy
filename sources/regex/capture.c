/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** capture.c
*/

#include "cregex.h"

static
bool regex_append(char ***array, size_t n, char *subject, regmatch_t match)
{
	size_t substr_len = 0;

	*array = my_realloc(*array, sizeof(char *) * (n + 2));
	if (*array == NULL)
		return (false);
	substr_len = match.rm_eo - match.rm_so;
	(*array)[n] = str_ndup(subject + match.rm_so, substr_len);
	if ((*array)[n] == NULL)
		return (false);
	return (true);
}

char **regex_capture(const char *pattern, char *subject)
{
	regex_t regex;
	int ok = regcomp(&regex, pattern, REG_EXTENDED);
	char **array = my_calloc(1, sizeof(char *));
	regmatch_t *matches = my_calloc(1, sizeof(regmatch_t));
	size_t n = 0;

	if (ok != 0 || (array == NULL || matches == NULL))
		return (NULL);
	for (; regexec(&regex, subject, 1, matches, 0) != REG_NOMATCH; ++n) {
		if (!regex_append(&array, n, subject, matches[0]))
			return (NULL);
		subject += matches[0].rm_eo;
	}
	regfree(&regex);
	my_free(matches);
	return (array);
}
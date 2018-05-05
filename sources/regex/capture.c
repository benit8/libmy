/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** capture.c
*/

#include "my/regex.h"

static bool regex_append(char ***array, size_t n, char *subject,
	regmatch_t *match)
{
	size_t substrlen = 0;

	*array = my_realloc(*array, sizeof(char *) * (n + 2));
	if (*array == NULL)
		return (false);
	substrlen = match->rm_eo - match->rm_so;
	(*array)[n] = my_strndup(subject + match->rm_so, substrlen);
	if ((*array)[n] == NULL)
		return (false);
	return (true);
}

char **regex_capture(const char *pattern, char *subject)
{
	regex_t regex;
	int ok = regcomp(&regex, pattern, REG_EXTENDED);
	char **array = my_calloc(1, sizeof(char *));
	regmatch_t match;
	size_t n = 0;

	if (ok != 0 || array == NULL)
		return (NULL);
	for (; regexec(&regex, subject, 1, &match, 0) != REG_NOMATCH; ++n) {
		if (!regex_append(&array, n, subject, &match))
			return (NULL);
		subject += match.rm_eo;
	}
	regfree(&regex);
	return (array);
}
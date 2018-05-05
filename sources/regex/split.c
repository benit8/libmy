/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** split.c
*/

#include "my/regex.h"

static bool append(char ***arr, size_t *n, const char *data, size_t len)
{
	char **narr = my_realloc(*arr, sizeof(char *) * (*n + 3));

	if (!narr)
		return (false);
	narr[*n] = my_strndup(data, len);
	if (!narr[*n])
		return (false);
	(*n)++;
	*arr = narr;
	return (true);
}

char **regex_split(char *pattern, char *subject)
{
	regex_t regex;
	regmatch_t match;
	size_t n = 0;
	char **array = my_calloc(1, sizeof(char *));

	if (array == NULL)
		return (NULL);
	if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
		free(array);
		return (NULL);
	}
	while (regexec(&regex, subject, 1, &match, 0) != REG_NOMATCH) {
		if (!append(&array, &n, subject, match.rm_so))
			return (array);
		subject += match.rm_eo;
	}
	regfree(&regex);
	if (!append(&array, &n, subject, match.rm_so))
		return (array);
	return (array);
}
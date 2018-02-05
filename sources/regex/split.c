/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** split.c
*/

#include "cregex.h"

char **regex_split(char *pattern, char *subject)
{
	char **array = my_calloc(1, sizeof(char *));
	regmatch_t *matches = my_calloc(1, sizeof(regmatch_t));
	regex_t regex;
	size_t n = 0;
	int rStatus = regcomp(&regex, pattern, REG_EXTENDED);

	if (rStatus != 0 || (matches == NULL || array == NULL))
		return (NULL);
	for (; regexec(&regex, subject, 1, matches, 0) != REG_NOMATCH; ++n) {
		array = my_realloc(array, sizeof(char *) * (n + 3));
		if (array == NULL)
			return (NULL);
		array[n] = my_calloc(matches[0].rm_so + 1, sizeof(char));
		str_ncpy(array[n], subject, matches[0].rm_so);
		subject += matches[0].rm_eo;
	}
	array[n++] = str_dup(subject);
	regfree(&regex);
	my_free(matches);
	return (array);
}
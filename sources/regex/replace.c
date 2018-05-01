/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** replace.c
*/

#include "my/regex.h"

char *regex_replace(const char *pattern, const char *replacement, char *subject)
{
	regex_t	regex;
	regmatch_t *matches = my_calloc(1, sizeof(regmatch_t));
	char *result = my_calloc(1, sizeof(char));
	int ok = regcomp(&regex, pattern, REG_EXTENDED);

	if (ok != 0 || matches == NULL || result == NULL)
		return (NULL);
	while (regexec(&regex, subject, 1, matches, 0) != REG_NOMATCH) {
		result = my_strnapd(result, subject, matches[0].rm_so);
		result = my_strapd(result, replacement);
		subject += matches[0].rm_eo;
	}
	result = my_strapd(result, subject);
	regfree(&regex);
	my_free(matches);
	return (result);
}
/*
** capture.c for libmy in /mnt/data/Delivery/Perso/libmy/regex
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 17 11:49:37 2017 Benoit Lormeau
** Last update Tue Oct 17 11:49:37 2017 Benoit Lormeau
*/

#include "cregex.h"

static bool regex_append(char ***array,
			   size_t n,
			   char *subject,
			   regmatch_t match)
{
	size_t subStrLength = 0;

	*array = my_realloc(*array, sizeof(char *) * (n + 2));
	if (*array == NULL)
		return (false);
	subStrLength = match.rm_eo - match.rm_so;
	(*array)[n] = str_ndup(subject + match.rm_so, subStrLength);
	if ((*array)[n] == NULL)
		return (false);
	return (true);
}

char **regex_capture(const char *pattern, char *subject)
{
	regex_t regex;
	int rStatus = regcomp(&regex, pattern, REG_EXTENDED);
	char **array = my_calloc(1, sizeof(char *));
	regmatch_t *matches = my_calloc(1, sizeof(regmatch_t));
	size_t n = 0;

	if (rStatus != 0 || (array == NULL || matches == NULL))
		return (NULL);
	for (; regexec(&regex, subject, 1, matches, 0) != REG_NOMATCH; ++n) {
		if (!regex_append(&array, n, subject, matches[0]))
			return (false);
		subject += matches[0].rm_eo;
	}
	regfree(&regex);
	my_free(matches);
	return (array);
}
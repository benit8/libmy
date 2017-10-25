/*
** capture.c for libmy in /mnt/data/Delivery/Perso/libmy/regex
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 17 11:49:37 2017 Benoit Lormeau
** Last update Tue Oct 17 11:49:37 2017 Benoit Lormeau
*/

#include "libmy.h"

static char **_regex_append(char **array,
                            size_t n,
                            char *subject,
                            regmatch_t match)
{
	size_t subStrLength = 0;

	array = my_realloc(array, sizeof(char *) * (n + 2));
	if (array == NULL)
		return (NULL);
	subStrLength = match.rm_eo - match.rm_so;
	array[n] = my_calloc(subStrLength + 1, sizeof(char));
	if (array[n] == NULL)
		return (NULL);
	str_ncpy(array[n], subject + match.rm_so, subStrLength);
	return (array);
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
	for (n = 0; regexec(&regex, subject, 1, matches, 0) != REG_NOMATCH; ++n){
		array = _regex_append(array, n, subject, matches[0]);
		subject += matches[0].rm_eo;
	}
	array[n] = NULL;
	regfree(&regex);
	my_free(matches);
	return (array);
}
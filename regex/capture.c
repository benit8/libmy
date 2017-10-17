/*
** capture.c for libmy in /mnt/data/Delivery/Perso/libmy/regex
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 17 11:49:37 2017 Benoit Lormeau
** Last update Tue Oct 17 11:49:37 2017 Benoit Lormeau
*/

#include <regex.h>
#include <stdlib.h>
#include <string.h>

char	**_Regex_append(char **array,
                        size_t n,
                        char *subject,
                        regmatch_t match)
{
	size_t subStrLength = 0;

	array = realloc(array, sizeof(char *) * (n + 2));
	if (array == NULL)
		return (NULL);
	subStrLength = match.rm_eo - match.rm_so;
	array[n] = calloc(subStrLength + 1, sizeof(char));
	if (array[n] == NULL)
		return (NULL);
	strncpy(array[n], subject + match.rm_so, subStrLength);
	return (array);
}

char	**Regex_capture(char *pattern, char *subject)
{
	regex_t regex;
	int rStatus = regcomp(&regex, pattern, REG_EXTENDED);
	char **array = calloc(1, sizeof(char *));
	regmatch_t *matches = calloc(1, sizeof(regmatch_t));
	size_t n = 0;

	if (rStatus != 0 || (array == NULL || matches == NULL))
		return (NULL);
	for (n = 0; regexec(&regex, subject, 1, matches, 0) != REG_NOMATCH; ++n){
		array = _Regex_append(array, n, subject, matches[0]);
		subject += matches[0].rm_eo;
	}
	array[n] = NULL;
	regfree(&regex);
	free(matches);
	return (array);
}
/*
** split.c for libmy in /mnt/data/Delivery/Perso/libmy/regex
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 17 15:05:27 2017 Benoit Lormeau
** Last update Tue Oct 17 15:05:27 2017 Benoit Lormeau
*/

#include <regex.h>
#include <stdlib.h>
#include <string.h>

char	**Regex_split(char *pattern, char *subject)
{
	char **array = calloc(1, sizeof(char *));
	regmatch_t *matches = calloc(1, sizeof(regmatch_t));
	regex_t regex;
	size_t n = 0;
	int rStatus = regcomp(&regex, pattern, REG_EXTENDED);

	if (rStatus != 0 || (matches == NULL || array == NULL))
		return (NULL);
	for (; regexec(&regex, subject, 1, matches, 0) != REG_NOMATCH; ++n){
		array = realloc(array, sizeof(char *) * (n + 3));
		if (array == NULL)
			return (NULL);
		array[n] = calloc(matches[0].rm_so + 1, sizeof(char));
		strncpy(array[n], subject, matches[0].rm_so);
		subject += matches[0].rm_eo;
	}
	array[n++] = strdup(subject);
	array[n] = NULL;
	regfree(&regex);
	free(matches);
	return (array);
}
/*
** count.c for libmy in /mnt/data/Delivery/Perso/libmy/regex
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 17 11:50:35 2017 Benoit Lormeau
** Last update Tue Oct 17 11:50:35 2017 Benoit Lormeau
*/

#include <regex.h>
#include <stdlib.h>

int	Regex_matchCount(char *pattern, char *string)
{
	regex_t regex;
	regmatch_t *matches = calloc(1, sizeof(regmatch_t));
	int ok = regcomp(&regex, pattern, REG_EXTENDED);
	int n = 0;

	if (ok != 0 || matches == NULL)
		return (-1);
	for (n = 0; regexec(&regex, string, 1, matches, 0) != REG_NOMATCH; ++n)
		string += matches[0].rm_eo;
	regfree(&regex);
	free(matches);
	return (n);
}
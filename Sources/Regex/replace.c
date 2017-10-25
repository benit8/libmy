/*
** replace.c for libmy in /mnt/data/Delivery/Perso/libmy/regex
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 17 14:41:55 2017 Benoit Lormeau
** Last update Tue Oct 17 14:41:55 2017 Benoit Lormeau
*/

#include "libmy.h"

char *regex_replace(const char *pattern, const char *replacement, char *subject)
{
	regex_t	regex;
	regmatch_t *matches = my_calloc(1, sizeof(regmatch_t));
	char *result = my_calloc(1, sizeof(char));
	int rStatus = regcomp(&regex, pattern, REG_EXTENDED);

	if (rStatus != 0 || matches == NULL || result == NULL)
		return (NULL);
	while (regexec(&regex, subject, 1, matches, 0) != REG_NOMATCH){
		result = str_napd(result, subject, matches[0].rm_so);
		result = str_apd(result, replacement);
		subject += matches[0].rm_eo;
	}
	result = str_apd(result, subject);
	regfree(&regex);
	my_free(matches);
	return (result);
}
/*
** replace.c for libmy in /mnt/data/Delivery/Perso/libmy/regex
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 17 14:41:55 2017 Benoit Lormeau
** Last update Tue Oct 17 14:41:55 2017 Benoit Lormeau
*/

#include <regex.h>
#include <stdlib.h>
#include <string.h>

char	*_Regex_strcat(char *dest, char *src)
{
	size_t  len;

	len = strlen(dest) + strlen(src);
	dest = realloc(dest, len + 1);
	dest = strcat(dest, src);
	dest[len] = '\0';
	return (dest);
}

char	*_Regex_strncat(char *dest, char *src, size_t n)
{
	size_t len;

	len = strlen(dest) + n;
	dest = realloc(dest, len + 1);
	dest = strncat(dest, src, n);
	dest[len] = '\0';
	return (dest);
}

char	*Regex_replace(char *pattern, char *replacement, char *subject)
{
	regex_t	regex;
	regmatch_t *matches = calloc(1, sizeof(regmatch_t));
	char *result = calloc(1, sizeof(char));
	int rStatus = regcomp(&regex, pattern, REG_EXTENDED);

	if (rStatus != 0 || matches == NULL || result == NULL)
		return (NULL);
	while (regexec(&regex, subject, 1, matches, 0) != REG_NOMATCH){
		result = _Regex_strncat(result, subject, matches[0].rm_so);
		result = _Regex_strcat(result, replacement);
		subject += matches[0].rm_eo;
	}
	result = _Regex_strcat(result, subject);
	regfree(&regex);
	free(matches);
	return (result);
}
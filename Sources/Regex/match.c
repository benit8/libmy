/*
** match.c for libmy in /mnt/data/Delivery/Perso/libmy/regex
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 17 14:57:10 2017 Benoit Lormeau
** Last update Tue Oct 17 14:57:10 2017 Benoit Lormeau
*/

#include "libmy.h"

bool regex_match(const char *pattern, char *subject)
{
	regex_t regex;
	int status = regcomp(&regex, pattern, REG_EXTENDED | REG_NOSUB);

	if (status != 0)
		return (false);
	status = regexec(&regex, subject, 0, NULL, 0);
	regfree(&regex);
	return (status != REG_NOMATCH ? true : false);
}
/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** lookup.c
*/

#include "network.h"

/*
** net_lookup
**
** Looks up information by resolving a DNS name and returns a pointer to the
** resolved IP address.
**
** Returns one of:
** 	NULL				Unable to resolve name.
** 	Pointer to resolved IP address	Must be freed by caller.
*/
char *net_lookup(const char *name)
{
	struct hostent *ent = NULL;
	char *hostname = NULL;
	char *temp = NULL;

	ent = gethostbyname(name);
	if (!ent) {
		my_fprintf(stderr, "Could not get host by name\n");
		return (NULL);
	}
	temp = inet_ntoa(*((struct in_addr *)ent->h_addr));
	hostname = my_calloc(str_len(temp) + 1, sizeof(char));
	str_cpy(hostname, temp);
	return (hostname);
}
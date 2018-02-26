/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** close.c
*/

#include "network.h"

/*
** net_close (TCP / UDP)
**
** Closes an net connection.
**
** Returns one of:
** 	0	Success.
** 	-1	Invalid `host` pointer.
*/
int net_close(net_host_t *host)
{
	if (!host)
		return (-1);
	if (host->fd)
		close(host->fd);
	return (0);
}
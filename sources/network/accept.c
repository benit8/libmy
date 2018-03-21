/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** accept.c
*/

#include "my/network.h"

/*
** net_accept (TCP:server)
**
** Accepts an incoming connection from the `remote` host to the `local` host.
**
** Returns one of:
** 	0		Success.
** 	-NET_E_PROT	Incorrect protocol.
** 	-NET_E_LSTN	Error listening.
** 	-NET_E_ACPT	Error accepting connection.
*/
int net_accept(net_host_t *remote, net_host_t *local)
{
	socklen_t ln = sizeof(remote->addr);

	if (local->protocol != NET_PROT_TCP) {
		my_fprintf(stderr, "Error accepting from non-TCP protocol\n");
		return (-NET_E_PROT);
	}
	if (listen(local->fd, NET_BACKLOG) < 0) {
		my_fprintf(stderr, "Error encountered while listening\n");
		return (-NET_E_LSTN);
	}
	remote->fd = accept(local->fd, (struct sockaddr *)&(remote->addr), &ln);
	if (remote->fd < 0) {
		my_fprintf(stderr, "Error accepting connection\n");
		return (-NET_E_ACPT);
	}
	return (0);
}
/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** connect.c
*/

#include "network.h"

/*
** net_connect (TCP:client)
**
** Connects the `local` host to the `remote` host.
**
** Returns one of:
** 	0		Success.
** 	-NET_E_PROT	Incorrect protocol.
** 	-NET_E_CONN	Error connecting to port.
**
** l.130
** Link `local->fd` and `remote->fd` on the client because `net_send` always
** sends data through `remote->fd` for TCP connections (this makes sense
** intuitively, as one would send data *to* a remote address). However, a TCP
** client (which would be the only host to call this function) always
** communicates through it's `local->fd` and leaves `remote->fd` unused so we
** may safely repurpose it for the sake of continuity.
*/
int net_connect(net_host_t *local, net_host_t *remote)
{
	if (local->protocol != NET_PROT_TCP) {
		my_fprintf(stderr, "Error accepting from non-TCP protocol\n");
		return (-NET_E_PROT);
	}
	if (connect(local->fd, (struct sockaddr *)&(remote->addr),
		sizeof(remote->addr)) < 0) {
		my_fprintf(stderr, "Error connecting to remote host\n");
		return (-NET_E_CONN);
	}
	remote->fd = local->fd;
	return (0);
}
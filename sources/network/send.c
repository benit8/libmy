/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** send.c
*/

#include "my/network.h"

/*
** net_send (TCP / UDP)
**
** Sends `len` bytes of `data` from `local` to `remote`.
**
** Returns one of:
** 	Number of bytes sent	Success.
** 	-NET_E_SEND		Error sending data.
*/
int net_send(net_host_t *local, net_host_t *remote, void *data, int len)
{
	int size = 0;

	switch (local->protocol) {
	case NET_PROT_TCP:
		size = send(remote->fd, data, len, 0);
		if (size < 0) {
			my_fprintf(stderr, "Error sending data\n");
			return (-NET_E_SEND);
		}
		break;
	case NET_PROT_UDP:
		size = sendto(local->fd, data, len, 0,
			(struct sockaddr *)&(remote->addr),
			sizeof(remote->addr));
		if (size < 0) {
			my_fprintf(stderr, "Error sending data\n");
			return (-NET_E_SEND);
		}
		break;
	}
	return (size);
}
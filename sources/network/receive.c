/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** receive.c
*/

#include "network.h"

static int receive_tcp(net_host_t *remote, void *data, int len, int timeout)
{
	fd_set fds;
	struct timeval time = {timeout, 0};
	int size = 0;

	FD_ZERO(&fds);
	FD_SET(remote->fd, &fds);
	if (timeout != -1)
		select(remote->fd + 1, &fds, NULL, NULL, &time);
	else
		select(remote->fd + 1, &fds, NULL, NULL, NULL);
	if (FD_ISSET(remote->fd, &fds)) {
		size = recv(remote->fd, data, len, 0);
		if (size < 0) {
			my_fprintf(stderr, "Error receiving data\n");
			return (-NET_E_RECV);
		}
		return (size);
	}
	return (-NET_E_TIME);
}

static int receive_udp(net_host_t *remote, net_host_t *local, void *data, int len, int timeout)
{
	fd_set fds;
	struct timeval time = {timeout, 0};
	socklen_t n = sizeof(remote->addr);
	int size = 0;

	FD_ZERO(&fds);
	FD_SET(local->fd, &fds);
	if (timeout != -1)
		select(local->fd + 1, &fds, NULL, NULL, &time);
	else
		select(local->fd + 1, &fds, NULL, NULL, NULL);
	if (FD_ISSET(local->fd, &fds)) {
		size = recvfrom(local->fd, data, len, 0,
			(struct sockaddr *)&(remote->addr), &n);
		if (size < 0) {
			my_fprintf(stderr, "Error receiving data\n");
			return (-NET_E_RECV);
		}
		return (size);
	}
	return (-NET_E_TIME);
}

/*
** net_receive (TCP / UDP)
**
** Receives a `len` bytes sent from `remote` to `local` and stores them in
** `data`. If no message is received within `timeout` seconds, -NET_E_TIME is
** returned.
**
** Setting `timeout` to 0 causes the function to return immediately if there is
** no data to receive and setting `timeout` to -1 causes the function to block
** until data is ready to be received.
**
** Returns one of:
** 	Number of bytes received	Success.
** 	-NET_E_TIME			Timeout.
** 	-NET_E_RECV			Error receiving data.
*/
int net_receive(net_host_t *remote, net_host_t *local, void *data, int len, int timeout)
{
	switch (local->protocol) {
		case NET_PROT_TCP:
			return (receive_tcp(remote, data, len, timeout));
		case NET_PROT_UDP:
			return (receive_udp(remote, local, data, len, timeout));
	}
	return (0);
}
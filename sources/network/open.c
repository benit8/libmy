/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** open.c
*/

#include "network.h"

/*
** net_setup (TCP:client / UDP:client)
**
** Sets up an net_host structure.
*/
static void net_setup(net_host_t *host, int protocol, const char *addr,
	unsigned short port)
{
	host->protocol = protocol;
	host->addr.sin_family = AF_INET;
	host->addr.sin_port = htons(port);
	host->addr.sin_addr.s_addr = NET_ADDR_ANY;
	if (addr != NET_ADDR_ANY)
		host->addr.sin_addr.s_addr = inet_addr(addr);
	mem_set(host->addr.sin_zero, 0, sizeof(host->addr.sin_zero));
}

/*
** net_open (TCP / UDP)
**
** Prepares `host` for transmission.
**
** `protocol` specifies the protocol to use for the transmission and is either
** `NET_PROT_TCP` or `NET_PROT_UDP`.
**
** `addr` is the IP address the host session structure will use: either a string
** of the form `X.X.X.X`, where each `X` is the textual representation of a
** number in the range 0 to 255, or `NET_ADDR_ANY` to specify the current host's
** IP address.
**
** `port` is the port number to bind to on the host machine. Specifying
** NET_PORT_ANY attempts to use any available port assigned by the kernel. Use
** this option when the port your host structure is bound to does not matter.
**
** Returns one of:
** 	0		Success.
** 	-NET_E_SOCK	Error acquiring socket file descriptor.
** 	-NET_E_BIND	Error binding socket to port.
*/
int net_open(net_host_t *host, int protocol, const char *addr,
	unsigned short port)
{
	host->fd = socket(PF_INET, protocol, 0);
	if (host->fd < 0) {
		my_fprintf(stderr, "Error acquiring socket file descriptor!\n");
		return (-NET_E_SOCK);
	}
	net_setup(host, protocol, addr, port);
	if (bind(host->fd, (struct sockaddr *)&(host->addr),
		sizeof(host->addr)) < 0) {
		my_fprintf(stderr, "Error acquiring socket file descriptor!\n");
		return (-NET_E_BIND);
	}
	host->protocol = protocol;
	return (0);
}
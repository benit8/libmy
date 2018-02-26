/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** network.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>

#include "io.h"
#include "memory.h"
#include "string.h"

////////////////////////////////////////////////////////////////////////////////

#define NET_PORT_ANY	(0)
#define NET_ADDR_ANY	INADDR_ANY

#define NET_PROT_TCP	SOCK_STREAM
#define NET_PROT_UDP	SOCK_DGRAM

// Number of simultaneous incoming connections to allow
#define NET_BACKLOG	(10)
#define NET_HOSTLEN	(64)

////////////////////////////////////////////////////////////////////////////////

// Set up our error codes
typedef enum net_err_code {
	NET_E_SOCK = 2,		// Error acquiring socket file descriptor
	NET_E_BIND,		// Error binding socket to port
	NET_E_CONN,		// Error connecting to port
	NET_E_PROT,		// Incorrect protocol
	NET_E_LSTN,		// Error listening
	NET_E_ACPT,		// Error accepting connection
	NET_E_SEND,		// Error sending data
	NET_E_RECV,		// Error receiving data
	NET_E_TIME,		// Timeout
} net_err_code_t;

// Structure representing an internet host
typedef struct net_host {
	int fd;
	int protocol;
	struct sockaddr_in addr;
} net_host_t;

////////////////////////////////////////////////////////////////////////////////

int net_open(net_host_t *host, int protocol, const char *addr, unsigned short port);
int net_accept(net_host_t *remote, net_host_t *local);
int net_connect(net_host_t *local, net_host_t *remote);
int net_receive(net_host_t *remote, net_host_t *local, void *data, int len, int timeout);
int net_send(net_host_t *local, net_host_t *remote, void *data, int len);
int net_close(net_host_t *host);
char *net_lookup(const char *name);

////////////////////////////////////////////////////////////////////////////////

/*
** The following two diagrams list the general order of function calls required
** to handle a session for TCP and UDP. The order of function calls in `SETUP'
** must be strictly followed; `TRANSMISSION' and `TEARDOWN' function calls may
** be done in any order and some examples are listed.
**
** Functions are labeled in the form ([TCP]:[client|server] /
** [UDP]:[client|server]) to denote whether the function is meant to be used by
** TCP, UDP, or either connection type and furthermore whether only clients,
** servers, or either are meant to call the function.
**
** +===========================================+
** |                    TCP                    |
** +=====================+=====================+
** |       SERVER        |        CLIENT       |
** +---------------------+---------------------+
** | net_open            | net_open            |\               \
** | net_accept          | net_setup           | | SETUP         |
** |                     | net_connect         |/                |
** |                     |                     |                 |
** | net_receive         | net_send            |\  TRANSMISSION   > SESSION
** | net_send            | net_receive         |/                |
** |                     |                     |                 |
** | net_close(local)    | net_close(local)    |\  TEARDOWN      |
** | net_close(remote)   |                     |/               /
** +---------------------+---------------------+
**
** +===========================================+
** |                    UDP                    |
** +=====================+=====================+
** |       SERVER        |       CLIENT        |
** +---------------------+---------------------+
** | net_open            | net_open            |\  SETUP        \
** |                     | net_setup           |/                |
** |                     |                     |                 |
** | net_receive         | net_send            |\  TRANSMISSION   > SESSION
** | net_send            | net_receive         |/                |
** |                     |                     |                 |
** | net_close           | net_close           |>  TEARDOWN     /
** +---------------------+---------------------+
*/
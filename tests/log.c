/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** tests / log.c
*/

#include "my/io/log.h"

int main(int ac, const char **av)
{
	log_set_program_name(av[0]);
	log_set_level(LL_ALL);

	log_debug("Debug");
	log_info("Info");
	log_warn("Warn");
	log_error("Error");
	log_fatal("Fatal");

	return 0;
}
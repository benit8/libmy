/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** io / log / data.c
*/

#include "io/log.h"

log_data_t *log_get_internal_data(void)
{
	static log_data_t data = {NULL, LL_WARN, STDERR_FILENO};

	return (&data);
}
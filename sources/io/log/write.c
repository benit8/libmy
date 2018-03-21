/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** io / log / write.c
*/

#include "my/io/log.h"

static const log_infos_t infos[] = {
	{NULL, NULL},
	{"DEBUG", MAGENTA},
	{"INFO", CYAN},
	{"WARN", YELLOW},
	{"ERROR", RED},
	{"FATAL", BG_BLACK BRED},
	{NULL, NULL}
};

static char *get_formatted_time(void)
{
	static char buff[64];
	time_t now = time(NULL);
	struct tm *info = localtime(&now);

	strftime(buff, 64, "%x %X", info);
	return (buff);
}

void log_write(const char *format, va_list *ap, log_level_t level)
{
	log_data_t *data = log_get_internal_data();

	if ((level <= LL_ALL || level >= LL_OFF) ||
		(level < data->level || data->fd < 0))
		return;
	my_dprintf(data->fd, "[%d] ", getpid());
	my_dprintf(data->fd, "[%s] ", get_formatted_time());
	if (data->fd < 3)
		my_dprintf(data->fd, infos[level].color);
	my_dprintf(data->fd, "[%s]", infos[level].name);
	if (data->fd < 3)
		my_dprintf(data->fd, RESET);
	my_dprintf(data->fd, " ");
	if (data->program_name)
		my_dprintf(data->fd, "%s: ", data->program_name);
	my_vdprintf(data->fd, format, *ap);
	my_dprintf(data->fd, "\n");
}
/*
** INI.h for Libmy in /mnt/data/Delivery/Perso/Libmy/Includes/parsing
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 11 16:58:42 2017 Benoit Lormeau
** Last update Mon Dec 11 16:58:42 2017 Benoit Lormeau
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>

#include "dsa/table.h"
#include "fs.h"
#include "io.h"
#include "memory.h"
#include "parsing/var.h"
#include "string.h"

////////////////////////////////////////////////////////////////////////////////

typedef struct ini_data
{
	table_t *vars;
	char *var_path;
} ini_data_t;

////////////////////////////////////////////////////////////////////////////////

ini_data_t *ini_init(void);
void ini_free(ini_data_t *ini);

ini_data_t *ini_parse(char *ini_string);
ini_data_t *ini_parse_file(const char *filepath);

bool ini_parse_line(ini_data_t *ini, char *line);
char *ini_epur_line(char *line);

bool ini_enter_section(ini_data_t *ini, char *line);
bool ini_leave_section(ini_data_t *ini, char *line);

bool ini_parse_var(ini_data_t *ini, char *line);
bool ini_insert_var(ini_data_t *ini, char *var, char *val);
bool ini_insert_array(ini_data_t *ini, char *var, char *val);

int ini_get_integer(ini_data_t *ini, const char *var);
double ini_get_decimal(ini_data_t *ini, const char *var);
char *ini_get_string(ini_data_t *ini, const char *var);
char **ini_get_array(ini_data_t *ini, const char *var);


size_t tab_size(char **tab);
void tab_free(char **tab);
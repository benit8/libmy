/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ini.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>

#include "my/dsa/list.h"
#include "my/dsa/map.h"
#include "my/memory.h"
#include "my/string.h"

////////////////////////////////////////////////////////////////////////////////

typedef struct ini
{
	map_t *keyvalues;
} ini_t;
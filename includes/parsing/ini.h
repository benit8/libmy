/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ini.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>

#include "dsa/list.h"
#include "dsa/map.h"
#include "memory.h"
#include "string.h"

////////////////////////////////////////////////////////////////////////////////

typedef struct ini
{
	map_t *keyvalues;
} ini_t;
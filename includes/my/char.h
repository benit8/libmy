/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** char.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>

////////////////////////////////////////////////////////////////////////////////

bool is_alnum(int c);
bool is_alpha(int c);
bool is_blank(int c);
bool is_cntrl(int c);
bool is_digit(int c);
bool is_graph(int c);
bool is_lower(int c);
bool is_print(int c);
bool is_punct(int c);
bool is_space(int c);
bool is_upper(int c);
bool is_xdigit(int c);

int to_lower(int c);
int to_upper(int c);
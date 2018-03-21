/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** calc.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include "my/dsa/queue.h"
#include "my/dsa/stack.h"
#include "my/math.h"
#include "my/numeric.h"
#include "my/string.h"

////////////////////////////////////////////////////////////////////////////////

void calc_parse_expr(const char *expr, queue_t *infix);
void calc_parse_infix(queue_t *infix, queue_t *postfix);
double calc_eval_postfix(queue_t *postfix);

int calc(const char *expr);
double fcalc(const char *expr);
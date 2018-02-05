/*
** calc.h for Libmy in /mnt/data/Delivery/Perso/Libmy/Includes/parsing
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Dec 13 20:24:29 2017 Benoit Lormeau
** Last update Wed Dec 13 20:24:29 2017 Benoit Lormeau
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include "dsa/queue.h"
#include "dsa/stack.h"
#include "math.h"
#include "numeric.h"
#include "string.h"

////////////////////////////////////////////////////////////////////////////////

int calc(const char *expr);
double fcalc(const char *expr);

void calc_parse_expr(const char *expr, queue_t *infix);
void calc_parse_infix(queue_t *infix, queue_t *postfix);
double calc_eval_postfix(queue_t *postfix);
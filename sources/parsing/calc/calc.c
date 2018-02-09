/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** calc.c
*/

#include "parsing/calc.h"

double fcalc(const char *expr)
{
	queue_t *infix = queue_create(&my_free);
	queue_t *postfix = queue_create(&my_free);
	double res = 0.0;

	calc_parse_expr(expr, infix);
	calc_parse_infix(infix, postfix);
	res = calc_eval_postfix(postfix);
	queue_destroy(infix);
	queue_destroy(postfix);
	return (res);
}

int calc(const char *expr)
{
	return ((int)fcalc(expr));
}
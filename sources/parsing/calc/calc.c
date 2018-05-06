/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** calc.c
*/

#include <stdio.h>
#include "my/parsing/calc.h"

double fcalc(const char *expr)
{
	queue_t *infix = NULL;
	queue_t *postfix = NULL;
	double res = 0.0;

	if (!expr)
		return (0.0);
	infix = queue_create(&my_free);
	postfix = queue_create(&my_free);
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
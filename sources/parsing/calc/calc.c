/*
** calc.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/parsing/calc
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Dec 13 20:26:08 2017 Benoit Lormeau
** Last update Wed Dec 13 20:26:08 2017 Benoit Lormeau
*/

#include "parsing/calc.h"

double fcalc(const char *expr)
{
	queue_t *infix = queue_create(&my_free);
	queue_t *postfix = queue_create(&my_free);
	double res;

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
/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** postfix.c
*/

#include "parsing/calc.h"

static double calc_do_operation(char symbol, char *s[2])
{
	double n[2];

	n[0] = my_atof(s[0]);
	n[1] = my_atof(s[1]);
	switch (symbol) {
	case '+':
		return (n[0] + n[1]);
	case '-':
		return (n[0] - n[1]);
	case '*':
		return (n[0] * n[1]);
	case '/':
		return (n[0] / n[1]);
	case '%':
		return (my_fmod(n[0], n[1]));
	case '^':
		return (my_pow(n[0], n[1]));
	default:
		return (0.0);
	}
}

static bool calc_prepare_operation(stack_t *stack, char *symbol)
{
	double res;
	char *s[2];
	bool r = true;

	s[1] = stack_pop(stack);
	s[0] = stack_pop(stack);
	if (s[0] == NULL || s[1] == NULL) {
		r = false;
		my_free(s[0]);
		my_free(s[1]);
		my_free(symbol);
		return (r);
	}
	res = calc_do_operation(*symbol, s);
	stack_push(stack, my_ftoa(res, 6));
	my_free(s[0]);
	my_free(s[1]);
	my_free(symbol);
	return (r);
}

double calc_eval_postfix(queue_t *postfix)
{
	stack_t *stack = stack_create(&my_free);
	double res = 0.0;
	char *str;

	for (char *symbol; !queue_is_empty(postfix); ) {
		symbol = queue_pop(postfix);
		if (!str_chr("+-*/%^", *symbol))
			stack_push(stack, symbol);
		else if (!calc_prepare_operation(stack, symbol)) {
			stack_destroy(stack);
			return (res);
		}
	}
	str = (char *)stack_pop(stack);
	if (str) {
		res = my_atof(str);
		my_free(str);
	}
	stack_destroy(stack);
	return (res);
}
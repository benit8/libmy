/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** expression.c
*/

#include "my/parsing/calc.h"

static bool is_var_char(char c)
{
	return (is_alnum(c) || c == '_');
}

static bool is_num_char(char c)
{
	return (is_digit(c) || c == '.');
}

static bool parse_identifier(const char *expr, size_t *i, int type,
	queue_t *infix)
{
	size_t s = *i;
	bool r = false;

	switch (type) {
	case 0:
		(*i)++;
		break;
	case 1:
		while (is_num_char(expr[*i]) || (expr[*i] == '-' && s == *i))
			(*i)++;
		break;
	case 2:
		for (; is_var_char(expr[*i]); (*i)++);
		break;
	}
	r = queue_push(infix, my_strndup(expr + s, (*i) - s));
	(*i)--;
	return (r);
}

void calc_parse_expr(const char *expr, queue_t *infix)
{
	for (size_t i = 0; expr[i] != '\0'; ++i) {
		if (expr[i] == '-' && is_num_char(expr[i + 1])) {
			parse_identifier(expr, &i, 1, infix);
			continue;
		}
		if (my_strchr("+-*/%^()", expr[i])) {
			parse_identifier(expr, &i, 0, infix);
			continue;
		}
		if (is_num_char(expr[i]))
			parse_identifier(expr, &i, 1, infix);
		else if (is_alpha(expr[i]))
			parse_identifier(expr, &i, 2, infix);
	}
}
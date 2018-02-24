/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** expression.c
*/

#include "parsing/calc.h"

static bool is_var_char(char c)
{
	return (is_alnum(c) || c == '_');
}

static bool is_num_char(char c)
{
	return (is_digit(c) || c == '.');
}

static bool parse_identifier(const char *expr, size_t *i, int8_t type,
	queue_t *infix)
{
	size_t start;
	bool r;

	switch (type) {
		case 0:
			start = (*i)++;
		break;
		case 1:
			for (start = *i; is_num_char(expr[*i]); (*i)++);
		break;
		case 2:
			for (start = *i; is_var_char(expr[*i]); (*i)++);
		break;
	}
	r = queue_push(infix, str_ndup(expr + start, (*i) - start));
	(*i)--;
	return (r);
}

void calc_parse_expr(const char *expr, queue_t *infix)
{
	for (size_t i = 0; expr[i] != '\0'; ++i) {
		if (str_chr("+-*/%^()", expr[i]))
			parse_identifier(expr, &i, 0, infix);
		else if (is_num_char(expr[i]))
			parse_identifier(expr, &i, 1, infix);
		else if (is_alpha(expr[i]))
			parse_identifier(expr, &i, 2, infix);
	}
}
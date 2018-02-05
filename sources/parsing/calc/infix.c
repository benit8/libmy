/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** infix.c
*/

#include "parsing/calc.h"

static int precdnc(char symbol)
{
	switch (symbol) {
		case '^':
			return (4);
		case '*':
		case '/':
		case '%':
			return (3);
		case '+':
		case '-':
			return (2);
		case '(':
		case ')':
		case '#':
		default:
			return (1);
	}
	return (0);
}

static void calc_parse_infix_2(queue_t *postfix, stack_t *stack, char *symbol)
{
	if (*symbol == ')') {
		while (!stack_is_empty(stack) && STACK_PEEK(stack, char) != '(')
			queue_push(postfix, stack_pop(stack));
		my_free(stack_pop(stack));
		my_free(symbol);
	}
	else if (precdnc(*symbol) > precdnc(STACK_PEEK(stack, char)))
		stack_push(stack, symbol);
	else {
		while (precdnc(*symbol) <= precdnc(STACK_PEEK(stack, char)))
			queue_push(postfix, stack_pop(stack));
		queue_push(postfix, symbol);
	}
}

void calc_parse_infix(queue_t *infix, queue_t *postfix)
{
	stack_t *stack = stack_create(&my_free);
	char *symbol;

	stack_push(stack, str_dup("#"));
	while (!queue_is_empty(infix)) {
		symbol = queue_pop(infix);
		if (!str_chr("+-*/%^()", *symbol))
			queue_push(postfix, symbol);
		else if (*symbol == '(')
			stack_push(stack, symbol);
		else
			calc_parse_infix_2(postfix, stack, symbol);
	}
	while (!stack_is_empty(stack) && STACK_PEEK(stack, char) != '#')
		queue_push(postfix, stack_pop(stack));
	stack_destroy(stack);
}
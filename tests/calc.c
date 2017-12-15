/*
** calc.c for Libmy tests in /mnt/data/Delivery/Perso/Libmy/Tests
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Dec 13 10:28:09 2017 Benoit Lormeau
** Last update Wed Dec 13 10:28:09 2017 Benoit Lormeau
*/

#include <stdio.h>
#include "libmy.h"

static bool is_var_char(char c)
{
	return (is_alnum(c) || c == '_');
}

static bool is_num_char(char c)
{
	return (is_alnum(c) || c == '.');
}

static int precedence(char symbol)
{
	switch (symbol) {
		case '+':
		case '-':
			return (2);
		case '*':
		case '/':
		case '%':
			return (3);
		case '^':
			return (4);
		case '(':
		case ')':
		case '#':
		default:
			return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	char **lines = file_get_lines("zdoc/z2.doc");
	for (size_t i = 0; lines[i]; ++i){
		printf("'%-20s': %f\n", lines[i], fcalc(lines[i]));
		my_free(lines[i]);
	}
	my_free(lines);
	return (0);




	char *expr = str_dup((ac < 2) ? "4 * (2 + 3)" : av[1]);
	printf("%s = %d\n", expr, calc(expr));
	my_free(expr);
	return (0);




	queue_t *infix = queue_create(&my_free);
	char *tmp;
	size_t start;

	/*
	 *  Infix parsing
	 */
	for (size_t i = 0; expr[i]; ++i){
		if (str_chr("+-*/%^()", expr[i])) {
			tmp = str_ndup(expr + i, 1);
			queue_push(infix, tmp);
		}
		else if (is_digit(expr[i])) {
			for (start = i; is_num_char(expr[i]); ++i);
			tmp = str_ndup(expr + start, i - start);
			queue_push(infix, tmp);
			--i;
		}
		else if (is_alpha(expr[i])) {
			for (start = i; is_var_char(expr[i]); ++i);
			tmp = str_ndup(expr + start, i - start);
			queue_push(infix, tmp);
			--i;
		}
	}


	stack_t *stack = stack_create(&my_free);
	queue_t *postfix = queue_create(&my_free);
	char *symbol;

	/*
	 *  Infix to Postfix conversion
	 */
	stack_push(stack, str_dup("#"));
	while (!queue_is_empty(infix)) {
		symbol = queue_pop(infix);

		if (!str_chr("+-*/%^()", *symbol))
			queue_push(postfix, symbol);
		else  if (*symbol == '(')
			stack_push(stack, symbol);
		else  if (*symbol == ')') {
			while (!stack_is_empty(stack) && STACK_PEEK(stack, char) != '(')
				queue_push(postfix, stack_pop(stack));
			my_free(stack_pop(stack));
			my_free(symbol);
		}
		else if (precedence(*symbol) > precedence(STACK_PEEK(stack, char)))
			stack_push(stack, symbol);
		else {
			while (precedence(*symbol) <= precedence(STACK_PEEK(stack, char)))
				queue_push(postfix, stack_pop(stack));
			queue_push(postfix, symbol);
		}
	}

	while (!stack_is_empty(stack) && STACK_PEEK(stack, char) != '#'){
		queue_push(postfix, stack_pop(stack));
	}


	/*
	 *  Postfix parsing
	 */
	stack_clear(stack);
	while (!queue_is_empty(postfix)) {
		symbol = queue_pop(postfix);
		if (!str_chr("+-*/%^", *symbol))
			stack_push(stack, symbol);
		else {
			char *s2 = stack_pop(stack);	double n2 = my_atof(s2);
			char *s1 = stack_pop(stack);	double n1 = my_atof(s1);
			double res = 0;
			switch (*symbol) {
				case '+': res = n1 + n2; break;
				case '-': res = n1 - n2; break;
				case '*': res = n1 * n2; break;
				case '/': res = n1 / n2; break;
				case '%': res = my_fmod(n1, n2); break;
				case '^': res = my_pow(n1, n2); break;
			}
			stack_push(stack, my_ftoa(res, 6));
			my_free(s1); my_free(s2);
			my_free(symbol);
		}
	}

	char *sfinal = (char *)stack_pop(stack);
	double final = my_atof(sfinal);
	my_free(sfinal);

	printf("result: %f\n", final);



	queue_destroy(infix);
	queue_destroy(postfix);
	stack_destroy(stack);
	my_free(expr);
	return (0);
}

/*


3 ^ 4.5 = 140.296115413
exp(log(3) * 4.5) = 8.55953311682


*/
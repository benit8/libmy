/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_graph.c
*/

#include <criterion/criterion.h>
#include "my/char.h"

Test(Char, is_graph)
{
	cr_expect(is_graph('\0') == false);
	cr_expect(is_graph('\t') == false);
	cr_expect(is_graph('\n') == false);
	cr_expect(is_graph(' ') == false);
	cr_expect(is_graph('!') == true);
	cr_expect(is_graph('$') == true);
	cr_expect(is_graph('(') == true);
	cr_expect(is_graph('1') == true);
	cr_expect(is_graph('=') == true);
	cr_expect(is_graph('@') == true);
	cr_expect(is_graph('B') == true);
	cr_expect(is_graph('H') == true);
	cr_expect(is_graph('[') == true);
	cr_expect(is_graph('a') == true);
	cr_expect(is_graph('z') == true);
	cr_expect(is_graph('}') == true);
	cr_expect(is_graph(127) == false);
}
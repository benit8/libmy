/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** to_lower.c
*/

#include <criterion/criterion.h>
#include "my/char.h"

Test(Char, to_lower)
{
	cr_expect(to_lower('\0') == '\0');
	cr_expect(to_lower('\t') == '\t');
	cr_expect(to_lower('\n') == '\n');
	cr_expect(to_lower(' ') == ' ');
	cr_expect(to_lower('!') == '!');
	cr_expect(to_lower('$') == '$');
	cr_expect(to_lower('(') == '(');
	cr_expect(to_lower('1') == '1');
	cr_expect(to_lower('=') == '=');
	cr_expect(to_lower('@') == '@');
	cr_expect(to_lower('B') == 'b');
	cr_expect(to_lower('H') == 'h');
	cr_expect(to_lower('[') == '[');
	cr_expect(to_lower('a') == 'a');
	cr_expect(to_lower('z') == 'z');
	cr_expect(to_lower('}') == '}');
	cr_expect(to_lower(127) == 127);
}
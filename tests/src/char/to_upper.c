/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** to_upper.c
*/

#include <criterion/criterion.h>
#include "my/char.h"

Test(Char, to_upper)
{
	cr_expect(to_upper('\0') == '\0');
	cr_expect(to_upper('\t') == '\t');
	cr_expect(to_upper('\n') == '\n');
	cr_expect(to_upper(' ') == ' ');
	cr_expect(to_upper('!') == '!');
	cr_expect(to_upper('$') == '$');
	cr_expect(to_upper('(') == '(');
	cr_expect(to_upper('1') == '1');
	cr_expect(to_upper('=') == '=');
	cr_expect(to_upper('@') == '@');
	cr_expect(to_upper('B') == 'B');
	cr_expect(to_upper('H') == 'H');
	cr_expect(to_upper('[') == '[');
	cr_expect(to_upper('a') == 'A');
	cr_expect(to_upper('z') == 'Z');
	cr_expect(to_upper('}') == '}');
	cr_expect(to_upper(127) == 127);
}
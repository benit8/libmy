/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_lower.c
*/

#include <criterion/criterion.h>
#include "my/char.h"

Test(Char, is_lower)
{
	cr_expect(is_lower('\0') == false);
	cr_expect(is_lower('\t') == false);
	cr_expect(is_lower('\n') == false);
	cr_expect(is_lower(' ') == false);
	cr_expect(is_lower('!') == false);
	cr_expect(is_lower('$') == false);
	cr_expect(is_lower('(') == false);
	cr_expect(is_lower('1') == false);
	cr_expect(is_lower('=') == false);
	cr_expect(is_lower('@') == false);
	cr_expect(is_lower('B') == false);
	cr_expect(is_lower('H') == false);
	cr_expect(is_lower('[') == false);
	cr_expect(is_lower('a') == true);
	cr_expect(is_lower('z') == true);
	cr_expect(is_lower('}') == false);
	cr_expect(is_lower(127) == false);
}
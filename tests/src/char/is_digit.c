/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_digit.c
*/

#include <criterion/criterion.h>
#include "my/char.h"

Test(Char, is_digit)
{
	cr_expect(is_digit('\0') == false);
	cr_expect(is_digit('\t') == false);
	cr_expect(is_digit('\n') == false);
	cr_expect(is_digit(' ') == false);
	cr_expect(is_digit('!') == false);
	cr_expect(is_digit('$') == false);
	cr_expect(is_digit('(') == false);
	cr_expect(is_digit('1') == true);
	cr_expect(is_digit('=') == false);
	cr_expect(is_digit('@') == false);
	cr_expect(is_digit('B') == false);
	cr_expect(is_digit('H') == false);
	cr_expect(is_digit('[') == false);
	cr_expect(is_digit('a') == false);
	cr_expect(is_digit('z') == false);
	cr_expect(is_digit('}') == false);
	cr_expect(is_digit(127) == false);
}
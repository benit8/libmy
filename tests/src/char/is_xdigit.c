/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_xdigit.c
*/

#include <criterion/criterion.h>
#include "my/char.h"

Test(Char, is_xdigit)
{
	cr_expect(is_xdigit('\0') == false);
	cr_expect(is_xdigit('\t') == false);
	cr_expect(is_xdigit('\n') == false);
	cr_expect(is_xdigit(' ') == false);
	cr_expect(is_xdigit('!') == false);
	cr_expect(is_xdigit('$') == false);
	cr_expect(is_xdigit('(') == false);
	cr_expect(is_xdigit('1') == true);
	cr_expect(is_xdigit('=') == false);
	cr_expect(is_xdigit('@') == false);
	cr_expect(is_xdigit('B') == true);
	cr_expect(is_xdigit('H') == false);
	cr_expect(is_xdigit('[') == false);
	cr_expect(is_xdigit('a') == true);
	cr_expect(is_xdigit('z') == false);
	cr_expect(is_xdigit('}') == false);
	cr_expect(is_xdigit(127) == false);
}
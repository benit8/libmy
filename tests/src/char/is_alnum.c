/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_alnum.c
*/

#include <criterion/criterion.h>
#include "my/char.h"

Test(Char, is_alnum)
{
	cr_expect(is_alnum('\0') == false);
	cr_expect(is_alnum('\t') == false);
	cr_expect(is_alnum('\n') == false);
	cr_expect(is_alnum(' ') == false);
	cr_expect(is_alnum('!') == false);
	cr_expect(is_alnum('$') == false);
	cr_expect(is_alnum('(') == false);
	cr_expect(is_alnum('1') == true);
	cr_expect(is_alnum('=') == false);
	cr_expect(is_alnum('@') == false);
	cr_expect(is_alnum('B') == true);
	cr_expect(is_alnum('H') == true);
	cr_expect(is_alnum('[') == false);
	cr_expect(is_alnum('a') == true);
	cr_expect(is_alnum('z') == true);
	cr_expect(is_alnum('}') == false);
	cr_expect(is_alnum(127) == false);
}
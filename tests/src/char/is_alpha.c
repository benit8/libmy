/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_alpha.c
*/

#include <criterion/criterion.h>
#include "my/char.h"

Test(Char, is_alpha)
{
	cr_expect(is_alpha('\0') == false);
	cr_expect(is_alpha('\t') == false);
	cr_expect(is_alpha('\n') == false);
	cr_expect(is_alpha(' ') == false);
	cr_expect(is_alpha('!') == false);
	cr_expect(is_alpha('$') == false);
	cr_expect(is_alpha('(') == false);
	cr_expect(is_alpha('1') == false);
	cr_expect(is_alpha('=') == false);
	cr_expect(is_alpha('@') == false);
	cr_expect(is_alpha('B') == true);
	cr_expect(is_alpha('H') == true);
	cr_expect(is_alpha('[') == false);
	cr_expect(is_alpha('a') == true);
	cr_expect(is_alpha('z') == true);
	cr_expect(is_alpha('}') == false);
	cr_expect(is_alpha(127) == false);
}
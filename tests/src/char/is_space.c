/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_space.c
*/

#include <criterion/criterion.h>
#include "my/char.h"

Test(Char, is_space)
{
	cr_expect(is_space('\0') == false);
	cr_expect(is_space('\t') == true);
	cr_expect(is_space('\n') == true);
	cr_expect(is_space(' ') == true);
	cr_expect(is_space('!') == false);
	cr_expect(is_space('$') == false);
	cr_expect(is_space('(') == false);
	cr_expect(is_space('1') == false);
	cr_expect(is_space('=') == false);
	cr_expect(is_space('@') == false);
	cr_expect(is_space('B') == false);
	cr_expect(is_space('H') == false);
	cr_expect(is_space('[') == false);
	cr_expect(is_space('a') == false);
	cr_expect(is_space('z') == false);
	cr_expect(is_space('}') == false);
	cr_expect(is_space(127) == false);
}
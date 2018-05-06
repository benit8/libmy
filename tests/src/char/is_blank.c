/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_blank.c
*/

#include <criterion/criterion.h>
#include "my/char.h"

Test(Char, is_blank)
{
	cr_expect(is_blank('\0') == false);
	cr_expect(is_blank('\t') == true);
	cr_expect(is_blank('\n') == false);
	cr_expect(is_blank(' ') == true);
	cr_expect(is_blank('!') == false);
	cr_expect(is_blank('$') == false);
	cr_expect(is_blank('(') == false);
	cr_expect(is_blank('1') == false);
	cr_expect(is_blank('=') == false);
	cr_expect(is_blank('@') == false);
	cr_expect(is_blank('B') == false);
	cr_expect(is_blank('H') == false);
	cr_expect(is_blank('[') == false);
	cr_expect(is_blank('a') == false);
	cr_expect(is_blank('z') == false);
	cr_expect(is_blank('}') == false);
	cr_expect(is_blank(127) == false);
}
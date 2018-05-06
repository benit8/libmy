/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_upper.c
*/

#include <criterion/criterion.h>
#include "my/char.h"

Test(Char, is_upper)
{
	cr_expect(is_upper('\0') == false);
	cr_expect(is_upper('\t') == false);
	cr_expect(is_upper('\n') == false);
	cr_expect(is_upper(' ') == false);
	cr_expect(is_upper('!') == false);
	cr_expect(is_upper('$') == false);
	cr_expect(is_upper('(') == false);
	cr_expect(is_upper('1') == false);
	cr_expect(is_upper('=') == false);
	cr_expect(is_upper('@') == false);
	cr_expect(is_upper('B') == true);
	cr_expect(is_upper('H') == true);
	cr_expect(is_upper('[') == false);
	cr_expect(is_upper('a') == false);
	cr_expect(is_upper('z') == false);
	cr_expect(is_upper('}') == false);
	cr_expect(is_upper(127) == false);
}
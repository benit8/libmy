/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_punct.c
*/

#include <criterion/criterion.h>
#include "my/char.h"

Test(Char, is_punct)
{
	cr_expect(is_punct('\0') == false);
	cr_expect(is_punct('\t') == false);
	cr_expect(is_punct('\n') == false);
	cr_expect(is_punct(' ') == false);
	cr_expect(is_punct('!') == true);
	cr_expect(is_punct('$') == true);
	cr_expect(is_punct('(') == true);
	cr_expect(is_punct('1') == false);
	cr_expect(is_punct('=') == true);
	cr_expect(is_punct('@') == true);
	cr_expect(is_punct('B') == false);
	cr_expect(is_punct('H') == false);
	cr_expect(is_punct('[') == true);
	cr_expect(is_punct('a') == false);
	cr_expect(is_punct('z') == false);
	cr_expect(is_punct('}') == true);
	cr_expect(is_punct(127) == false);
}
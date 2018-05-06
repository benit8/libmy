/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_cntrl.c
*/

#include <criterion/criterion.h>
#include "my/char.h"

Test(Char, is_cntrl)
{
	cr_expect(is_cntrl('\0') == true);
	cr_expect(is_cntrl('\t') == true);
	cr_expect(is_cntrl('\n') == true);
	cr_expect(is_cntrl(' ') == false);
	cr_expect(is_cntrl('!') == false);
	cr_expect(is_cntrl('$') == false);
	cr_expect(is_cntrl('(') == false);
	cr_expect(is_cntrl('1') == false);
	cr_expect(is_cntrl('=') == false);
	cr_expect(is_cntrl('@') == false);
	cr_expect(is_cntrl('B') == false);
	cr_expect(is_cntrl('H') == false);
	cr_expect(is_cntrl('[') == false);
	cr_expect(is_cntrl('a') == false);
	cr_expect(is_cntrl('z') == false);
	cr_expect(is_cntrl('}') == false);
	cr_expect(is_cntrl(127) == true);
}
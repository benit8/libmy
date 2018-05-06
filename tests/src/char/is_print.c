/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** is_print.c
*/

#include <criterion/criterion.h>
#include "my/char.h"

Test(Char, is_print)
{
	cr_expect(is_print('\0') == false);
	cr_expect(is_print('\t') == false);
	cr_expect(is_print('\n') == false);
	cr_expect(is_print(' ') == true);
	cr_expect(is_print('!') == true);
	cr_expect(is_print('$') == true);
	cr_expect(is_print('(') == true);
	cr_expect(is_print('1') == true);
	cr_expect(is_print('=') == true);
	cr_expect(is_print('@') == true);
	cr_expect(is_print('B') == true);
	cr_expect(is_print('H') == true);
	cr_expect(is_print('[') == true);
	cr_expect(is_print('a') == true);
	cr_expect(is_print('z') == true);
	cr_expect(is_print('}') == true);
	cr_expect(is_print(127) == false);
}
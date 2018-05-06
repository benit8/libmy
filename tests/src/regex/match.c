/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** match.c
*/

#include <criterion/criterion.h>
#include "my/regex.h"

Test(Regex, match)
{
	cr_assert(regex_match(NULL, NULL) == -1);
	cr_assert(regex_match("^[0--9]$", NULL) == -1);
	cr_expect(regex_match("^-{1,2}h(elp)?$", "-h") == 1);
	cr_expect(regex_match("^-{1,2}h(elp)?$", "-help") == 1);
	cr_expect(regex_match("^-{1,2}h(elp)?$", "--h") == 1);
	cr_expect(regex_match("^-{1,2}h(elp)?$", "--help") == 1);
	cr_expect(regex_match("^-{1,2}h(elp)?$", "-he") == 0);
	cr_expect(regex_match("^-{1,2}h(elp)?$", "--he") == 0);
}
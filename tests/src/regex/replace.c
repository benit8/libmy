/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** replace.c
*/

#include <criterion/criterion.h>
#include "my/regex.h"

static void replace_test(char *pattern, char *replacement, char *subject, char *expect)
{
	char *str = regex_replace(pattern, replacement, subject);

	cr_assert(str != NULL);
	cr_expect_str_eq(str, expect);
	my_free(str);
}

Test(Regex, replace)
{
	replace_test("\\.", ",", "127.0.0.1", "127,0,0,1");
	replace_test("[ \t]+", " ", "hell   is	close", "hell is close");
	replace_test("[0-9]+", "NUM", "0xa65fed5b", "NUMxaNUMfedNUMb");
	replace_test("[0-9]", "NUM", "0xa65fed5b", "NUMxaNUMNUMfedNUMb");
}
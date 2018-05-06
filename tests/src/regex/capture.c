/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** capture.c
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include "my/regex.h"

Test(Regex, capture)
{
	char **matches = regex_capture(
		"([0-9]+)",
		"Ljj3f9ru6REMO6UCnxxqKdXXgZ3mOLfO5pFAJ9b7QKVwtXyo6kSIhCX5b7EwhnD0pjjqOepM2hyEAOnbXQ2TISRUuFbKN64ywAvn"
	);

	cr_assert(matches != NULL);
	cr_assert(matches[15] == NULL);

	cr_assert_str_eq(matches[0], "3");
	cr_assert_str_eq(matches[1], "9");
	cr_assert_str_eq(matches[2], "6");
	cr_assert_str_eq(matches[3], "6");
	cr_assert_str_eq(matches[4], "3");
	cr_assert_str_eq(matches[5], "5");
	cr_assert_str_eq(matches[6], "9");
	cr_assert_str_eq(matches[7], "7");
	cr_assert_str_eq(matches[8], "6");
	cr_assert_str_eq(matches[9], "5");
	cr_assert_str_eq(matches[10], "7");
	cr_assert_str_eq(matches[11], "0");
	cr_assert_str_eq(matches[12], "2");
	cr_assert_str_eq(matches[13], "2");
	cr_assert_str_eq(matches[14], "64");

	// Cleanup
	for (size_t i = 0; matches[i] != NULL; ++i)
		my_free(matches[i]);
	my_free(matches);
}
/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** split.c
*/

#include <criterion/criterion.h>
#include "my/regex.h"

Test(Regex, split)
{
	char **matches = regex_split(
		"([0-9]+)",
		"Ljj3f9ru6REMO6UCnxxqKdXXgZ3mOLfO5pFAJ9b7QKVwtXyo6kSIhCX5b7EwhnD0pjjqOepM2hyEAOnbXQ2TISRUuFbKN64ywAvn"
	);

	cr_assert(matches != NULL);
	cr_assert(matches[16] == NULL);

	cr_assert_str_eq(matches[0], "Ljj");
	cr_assert_str_eq(matches[1], "f");
	cr_assert_str_eq(matches[2], "ru");
	cr_assert_str_eq(matches[3], "REMO");
	cr_assert_str_eq(matches[4], "UCnxxqKdXXgZ");
	cr_assert_str_eq(matches[5], "mOLfO");
	cr_assert_str_eq(matches[6], "pFAJ");
	cr_assert_str_eq(matches[7], "b");
	cr_assert_str_eq(matches[8], "QKVwtXyo");
	cr_assert_str_eq(matches[9], "kSIhCX");
	cr_assert_str_eq(matches[10], "b");
	cr_assert_str_eq(matches[11], "EwhnD");
	cr_assert_str_eq(matches[12], "pjjqOepM");
	cr_assert_str_eq(matches[13], "hyEAOnbXQ");
	cr_assert_str_eq(matches[14], "TISRUuFbKN");
	cr_assert_str_eq(matches[15], "ywAvn");

	// Cleanup
	for (size_t i = 0; matches[i] != NULL; ++i)
		my_free(matches[i]);
	my_free(matches);
}
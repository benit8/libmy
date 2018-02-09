/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** str_natcmp.c
*/

#include "string.h"

int str_natcmp(const char *s1, const char *s2)
{
	int n1 = 0;
	int n2 = 0;

	for (; *s1 && *s2; s1++, s2++){
		if (is_digit(*s1) && is_digit(*s2)){
			n1 = my_strtol(s1, (char **)&s1, 10);
			n2 = my_strtol(s2, (char **)&s2, 10);
			if (n1 != n2)
				return (n1 - n2);
		}
		if (*s1 != *s2)
			break;
	}
	return (*s1 - *s2);
}

int str_nnatcmp(const char *s1, const char *s2, size_t n)
{
	int n1 = 0;
	int n2 = 0;

	for (; *s1 && *s2 && n--; s1++, s2++){
		if (is_digit(*s1) && is_digit(*s2)){
			n1 = my_strtol(s1, (char **)&s1, 10);
			n2 = my_strtol(s2, (char **)&s2, 10);
			if (n1 != n2)
				return (n1 - n2);
		}
		if (*s1 != *s2)
			break;
	}
	return (*s1 - *s2);
}
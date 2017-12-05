/*
** str_natcmp.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/String
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Dec 5 15:12:25 2017 Benoit Lormeau
** Last update Tue Dec 5 15:12:25 2017 Benoit Lormeau
*/

#include "String.h"

int str_natcmp(const char *s1, const char *s2)
{
	int n1;
	int n2;

	for ( ; *s1 && *s2; s1++, s2++){
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
	int n1;
	int n2;

	for ( ; *s1 && *s2 && n--; s1++, s2++){
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
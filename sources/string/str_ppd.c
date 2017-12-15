/*
** str_ppd.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/String
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Fri Nov 10 14:25:47 2017 Benoit Lormeau
** Last update Fri Nov 10 14:45:32 2017 Benoit Lormeau
*/

#include "string.h"

char *str_ppd(char *string, const char *span)
{
	size_t n = str_len(span);

	string = str_rev(string);
	string = str_napd(string, span, n);
	return (str_rev(string));
}

char *str_nppd(char *string, const char *span, size_t n)
{
	string = str_rev(string);
	string = str_napd(string, span, n);
	return (str_rev(string));
}
/*
** strrev.c for libmy.c in /mnt/data/Delivery/Perso/libmy/Sources/String
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 10:11:53 2017 Benoit Lormeau
** Last update Wed Oct 25 10:11:53 2017 Benoit Lormeau
*/

#include "libmy.h"

char *str_rev(char *str)
{
	size_t l = str_len(str);
	char t;

	for (size_t i = 0; i < l / 2; ++i){
		t = str[i];
		str[i] = str[l - i - 1];
		str[l - i - 1] = t;
	}
	return (str);
}
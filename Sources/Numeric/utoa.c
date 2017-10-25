/*
** utoa.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Numeric
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 10:30:02 2017 Benoit Lormeau
** Last update Wed Oct 25 10:30:02 2017 Benoit Lormeau
*/

#include "libmy.h"

char *my_utoa(size_t n)
{
	size_t i = 0;
	size_t len = uintlen(n);
	char *res = my_calloc(len + 1, sizeof(char));

	if (res == NULL)
		return (NULL);
	for (i = 0; i < len; ++i){
		res[i] = (n % 10) + '0';
		n /= 10;
	}
	return (my_strrev(res));
}
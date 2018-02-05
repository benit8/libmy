/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** putnbr.c
*/

#include "io.h"

void my_putnbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		my_putnbr(nb / 10);
	my_putchar((nb % 10) + '0');
}
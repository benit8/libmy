/*
** my_putnbr.c for libmy in /mnt/data/Delivery/Perso/libmy/puts
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 09:56:54 2017 Benoit Lormeau
** Last update Mon Oct 23 09:56:54 2017 Benoit Lormeau
*/

#include "libmy.h"

void my_putnbr(int nb)
{
	if (nb < 0){
		my_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		my_putnbr(nb / 10);
	my_putchar((nb % 10) + '0');
}
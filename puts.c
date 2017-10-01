/*
** puts.c for Code in /home/benito/Dropbox/Code
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Jun 20 17:57:41 2017 Benoit Lormeau
** Last update Tue Jun 20 17:57:41 2017 Benoit Lormeau
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *s)
{
  return (*s ? 1 + my_strlen(s + 1) : 0);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void	my_putnbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb > 9)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + '0');
}

int	my_getnbr(char *str)
{
  int	res;

  if (*str == '+')
    return (my_getnbr(str + 1));
  if (*str == '-')
    return (-my_getnbr(str + 1));
  res = 0;
  while (*str >= '0' && *str <= '9')
    {
      res = (res * 10) + (*str - '0');
      str++;
    }
  return (res);
}
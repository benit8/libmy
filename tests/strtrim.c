#include <stdio.h>
#include "Libmy.h"

int main(int ac, char **av)
{
	if (ac < 2)
		return (1);

	char *str = str_dup(av[1]);

	printf("orig: [%s]\n", str);
	str = str_trim(str);
	printf("trim: [%s]\n", str);

	my_free(str);
	return (0);
}

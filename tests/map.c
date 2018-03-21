/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ordered_map.c
*/

#include "my.h"

void display(const char *key, void *value)
{
	printf("%s: %lu\n", key, (size_t)value);
}

int main(void)
{
	map_t *map = map_create(NULL);

	map_insert(map, "b", (void*)('b' - 'a' + 1));
	map_insert(map, "a", (void*)('a' - 'a' + 1));
	map_insert(map, "z", (void*)('z' - 'a' + 1));
	map_insert(map, "c", (void*)('c' - 'a' + 1));
	map_insert(map, "f", (void*)('f' - 'a' + 1));

	map_foreach(map, &display);

	map_destroy(map);
	return (0);
}
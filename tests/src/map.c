/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ordered_map.c
*/

#include "my.h"

void display(const char *key, void *value)
{
	printf("%s: %c\n", key, (char)value);
}

int main(void)
{
	map_t *map = map_create(NULL);

	map_insert(map, "b", (void *)'b');
	map_insert(map, "a", (void *)'a');
	map_insert(map, "z", (void *)'z');
	map_insert(map, "c", (void *)'c');
	map_insert(map, "f", (void *)'f');

	map_foreach(map, &display);

	map_destroy(map);
	return (0);
}
/*
** ini.c for Libmy tests in /mnt/data/Delivery/Perso/Libmy/Tests
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 11 16:57:46 2017 Benoit Lormeau
** Last update Mon Dec 11 16:57:46 2017 Benoit Lormeau
*/

#include "Libmy.h"
#include <stdio.h>

int main(void)
{
	ini_data_t *ini = ini_parse_file("zdoc/z1.doc");
	if (!ini)
		perror("ini_parse_file");
	else {
		printf("\n====================  DEBUG  ====================\n");

		for (table_node_t *cur = ini->vars->head; cur != NULL; cur = cur->next){
			var_t *var = (var_t *)cur->data;
			switch (var->type){
				case ARRAY:
					printf("[%s] => ARRAY\n", cur->key);
					for (size_t i = 0; var->value.array[i] != NULL; ++i)
						printf("\t[%lu]: '%s'\n", i, var->value.array[i]);
				break;
				default:
					printf("[%s] => '%s'\n", cur->key, var->value.string);
				break;
			}
		}

		printf("\n==================== TESTING ====================\n");

		int integer = ini_get_integer(ini, "WIDTH");
		printf("integer: WIDTH = '%d'\n", integer);

		double decimal = ini_get_decimal(ini, "scale");
		printf("decimal: scale = '%f'\n", decimal);

		char *string = ini_get_string(ini, "dog:texture");
		printf("string: dog:texture = '%s'\n", string);

		char *nstring = ini_get_string(ini, "dog:animations:walk");
		printf("not string: dog:animations:walk = '%s'\n", nstring);

		char **array = ini_get_array(ini, "dog:animations:walk");
		char *array_c = implode(" | ", array);
		printf("array: dog:animations:walk = [%s]\n", array_c);
		my_free(array_c);

		char **narray = ini_get_array(ini, "dog:animations");
		printf("not array: dog:animations = %p\n", narray);
	}

	ini_free(ini);
	return (0);
}
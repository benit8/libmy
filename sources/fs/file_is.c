/*
** file_is.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/FS
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Thu Nov 9 14:54:02 2017 Benoit Lormeau
** Last update Thu Nov 9 14:54:02 2017 Benoit Lormeau
*/

#include "fs.h"

bool file_is(const char *filepath, const char *mask)
{
	int mode = 0;

	for (; *mask != '\0'; ++mask){
		switch (*mask){
			case 'f':
				mode |= F_OK;
			break;
			case 'r':
				mode |= R_OK;
			break;
			case 'w':
				mode |= W_OK;
			break;
			case 'x':
				mode |= X_OK;
			break;
		}
	}
	return (access(filepath, mode) != -1);
}
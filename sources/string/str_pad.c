/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** str_pad.c
*/

#include "string.h"

char *str_padr(const char *string, size_t padSize, const char *pad)
{
	size_t stringLen = str_len(string);
	size_t padLen = str_len(pad);
	char *output;

	if (padSize <= stringLen)
		return (str_dup(string));
	output = my_calloc(padSize + 1, sizeof(char));
	str_cpy(output, string);
	for (size_t i = stringLen; i < padSize; i += padLen)
		str_ncat(output, pad, MIN(padSize - i, padLen));
	return (output);
}

char *str_padl(const char *string, size_t padSize, const char *pad)
{
	size_t stringLen = str_len(string);
	size_t padLen = str_len(pad);
	size_t padSpace;
	char *output;

	if (padSize <= stringLen)
		return (str_dup(string));
	output = my_calloc(padSize + 1, sizeof(char));
	padSpace = padSize - stringLen;
	for (size_t i = 0; i < padSpace; i += padLen)
		str_ncat(output, pad, MIN(padSpace - i, padLen));
	str_cat(output, string);
	return (output);
}

char *str_pad(const char *string, size_t padSize, const char *pad)
{
	size_t stringLen = str_len(string);
	size_t pad_left = (padSize - stringLen) / 2;
	char *output1 = str_padl(string, pad_left + stringLen, pad);
	char *output2 = str_padr(output1, padSize, pad);

	my_free(output1);
	return (output2);
}
/*
** strpad.c for libmy.h in /mnt/data/Delivery/Perso/libmy/Sources/String
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 16:34:31 2017 Benoit Lormeau
** Last update Wed Oct 25 16:34:31 2017 Benoit Lormeau
*/

#include "libmy.h"

char *str_padr(char *input, size_t padSize, char *pad)
{
	size_t inputLen = str_len(input);
	size_t padLen = str_len(pad);
	char *output;

	if (padSize <= inputLen)
		return (str_dup(input));
	output = my_calloc(padSize + 1, sizeof(char));
	str_cpy(output, input);
	for (size_t i = inputLen; i < padSize; i += padLen)
		str_ncat(output, pad, MIN(padSize - i, padLen));
	return (output);
}

char *str_padl(char *input, size_t padSize, char *pad)
{
	size_t inputLen = str_len(input);
	size_t padLen = str_len(pad);
	size_t padSpace;
	char *output;

	if (padSize <= inputLen)
		return (str_dup(input));
	output = my_calloc(padSize + 1, sizeof(char));
	padSpace = padSize - inputLen;
	for (size_t i = 0; i < padSpace; i += padLen)
		str_ncat(output, pad, MIN(padSpace - i, padLen));
	str_cat(output, input);
	return (output);
}

char *str_pad(char *input, size_t padSize, char *pad)
{
	size_t inputLen = str_len(input);
	size_t pad_left = (padSize - inputLen) / 2;
	char *output1 = str_padl(input, pad_left + inputLen, pad);
	char *output2 = str_padr(output1, padSize, pad);

	my_free(output1);
	return (output2);
}
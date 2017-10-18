/*
** climits.c for C Limits in /home/benito/bin
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Thu Sep 28 09:39:52 2017 Benoit Lormeau
** Last update Thu Sep 28 09:46:14 2017 Benoit Lormeau
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

#define RESET		"\x1b[0m"
#define FAINT		"\x1b[2m"
#define UNDERLINE	"\x1b[4m"
#define RED		"\x1b[31m"
#define MAGENTA		"\x1b[35m"
#define CYAN		"\x1b[36m"

int main(void)
{
	printf(FAINT);
	printf("/*\n");
	printf("**\n");
	printf("** " UNDERLINE "C Limits\n" RESET);
	printf(FAINT);
	printf("**\n");
	printf("*/\n\n");
	printf(RESET);


	printf(MAGENTA "1" RESET " Byte = " MAGENTA "%d" RESET " Bits\n\n", CHAR_BIT);

	printf(CYAN "        " RED " CHAR " RESET " [" MAGENTA "%4d" RESET "," MAGENTA "%4d" RESET "]\n",        CHAR_MIN,  CHAR_MAX);
	printf(CYAN "  SIGNED" RED " CHAR " RESET " [" MAGENTA "%4d" RESET "," MAGENTA "%4d" RESET "]\n",       SCHAR_MIN, SCHAR_MAX);
	printf(CYAN "UNSIGNED" RED " CHAR " RESET " [" MAGENTA "%4d" RESET "," MAGENTA "%4d" RESET "]\n\n",             0, UCHAR_MAX);

	printf(CYAN "        " RED " SHORT" RESET " [" MAGENTA "%6d" RESET "," MAGENTA "%6d" RESET "]\n",        SHRT_MIN,  SHRT_MAX);
	printf(CYAN "UNSIGNED" RED " SHORT" RESET " [" MAGENTA "%6d" RESET "," MAGENTA "%6d" RESET "]\n\n",             0, USHRT_MAX);

	printf(CYAN "        " RED " INT  " RESET " [" MAGENTA "%11d" RESET "," MAGENTA "%11d" RESET "]\n",       INT_MIN,   INT_MAX);
	printf(CYAN "UNSIGNED" RED " INT  " RESET " [" MAGENTA "%11d" RESET "," MAGENTA "%11u" RESET "]\n\n",           0,  UINT_MAX);

	printf(CYAN "        " RED " LONG " RESET " [" MAGENTA "%20ld" RESET "," MAGENTA "%21ld" RESET "]\n",    LONG_MIN,  LONG_MAX);
	printf(CYAN "UNSIGNED" RED " LONG " RESET " [" MAGENTA "%20ld" RESET "," MAGENTA "%21lu" RESET "]\n\n",         0, ULONG_MAX);

	printf(CYAN "        " RED " FLOAT" RESET " [" MAGENTA "%12e" RESET "," MAGENTA "%14e" RESET "]\n",       FLT_MIN,   FLT_MAX);
	printf(CYAN "        " RED "DOUBLE" RESET " [" MAGENTA "%13e" RESET "," MAGENTA "%14e" RESET "]\n",       DBL_MIN,   DBL_MAX);

	return (0);
}
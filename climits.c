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

int main(void)
{
  printf("/**\n");
  printf(" *\n");
  printf(" * C Limits\n");
  printf(" *\n");
  printf(" */\n\n");


  printf("1 Byte = %d Bits\n\n", CHAR_BIT);

  printf("         CHAR  [%4d,%4d]\n",        CHAR_MIN,  CHAR_MAX);
  printf("  SIGNED CHAR  [%4d,%4d]\n",       SCHAR_MIN, SCHAR_MAX);
  printf("UNSIGNED CHAR  [%4d,%4d]\n\n",             0, UCHAR_MAX);

  printf("         SHORT [%6d,%6d]\n",        SHRT_MIN,  SHRT_MAX);
  printf("UNSIGNED SHORT [%6d,%6d]\n\n",             0, USHRT_MAX);

  printf("         INT   [%11d,%11d]\n",       INT_MIN,   INT_MAX);
  printf("UNSIGNED INT   [%11d,%11u]\n\n",           0,  UINT_MAX);

  printf("         LONG  [%20ld,%21ld]\n",    LONG_MIN,  LONG_MAX);
  printf("UNSIGNED LONG  [%20ld,%21lu]\n\n",         0, ULONG_MAX);

  printf("         FLOAT [%12e,%14e]\n",       FLT_MIN,   FLT_MAX);
  printf("        DOUBLE [%13e,%14e]\n",       DBL_MIN,   DBL_MAX);

  return (0);
}
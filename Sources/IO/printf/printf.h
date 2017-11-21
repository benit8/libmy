/*
** printf.h for libmy in /mnt/data/Delivery/Perso/libmy/Sources/IO/printf
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Nov 21 14:46:05 2017 Benoit Lormeau
** Last update Tue Nov 21 14:46:05 2017 Benoit Lormeau
*/

#pragma once

#define PRTF_CHARS	"-+~.*0123456789bcdefghilopsuxX%"
#define PRTF_OPT_DFLT	(printfOpt_t){PRTF_RIGHT, 0, 0, 0, 10, 0, 0, 0}

typedef enum
{
	PRTF_RIGHT,
	PRTF_LEFT,
	PRTF_CENTER,
	PRTF_RIGHT0
}	printfAlign;

typedef struct	printfOpt
{
	printfAlign	align;
	bool		prec;
	int		precLen;
	int		padSize;
	int		base;
	bool		sign;
	bool		unsign;
	bool		longlong;
}		printfOpt_t;

bool printf_process(const char **, char **, va_list);
bool printf_process_numeric(const char **, char **, va_list, printfOpt_t *);
void printf_process_padding(char **, printfOpt_t);

void printf_get_opt(const char **, va_list, printfOpt_t *);
void printf_get_opt_ap(va_list, printfOpt_t *);
void printf_get_opt_fmt(const char **, printfOpt_t *);
void printf_get_opt_num(const char **, char **, printfOpt_t *);

void printf_print_char(char **, va_list);
void printf_print_str(char **, va_list, printfOpt_t);
void printf_print_numeric(const char **, char **, va_list, printfOpt_t *);
void printf_print_float(const char **, char **, va_list, printfOpt_t *);
/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** printf.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#define PRTF_CHARS	"-+~.*0123456789bcdefghilopsuxX%"
#define PRTF_OPT_DFLT	(printf_opt_t){PRTF_RIGHT, 0, 0, 0, 10, 0, 0, 0}

////////////////////////////////////////////////////////////////////////////////

typedef enum
{
	PRTF_RIGHT,
	PRTF_LEFT,
	PRTF_CENTER,
	PRTF_RIGHT0
}	printf_align_t;

////////////////////////////////////////////////////////////////////////////////

typedef struct printfOpt
{
	printf_align_t align;
	bool prec;
	int prec_len;
	int pad_size;
	int base;
	bool sign;
	bool unsign;
	bool longlong;
} printf_opt_t;

////////////////////////////////////////////////////////////////////////////////

bool printf_process(const char **, char **, va_list);
bool printf_process_numeric(const char **, char **, va_list, printf_opt_t *);
void printf_process_padding(char **, printf_opt_t);

void printf_get_opt(const char **, va_list, printf_opt_t *);
void printf_get_opt_ap(va_list, printf_opt_t *);
void printf_get_opt_fmt(const char **, printf_opt_t *);
void printf_get_opt_num(const char **, char **, printf_opt_t *);

void printf_print_char(char **, va_list);
void printf_print_str(char **, va_list, printf_opt_t);
void printf_print_numeric(const char **, char **, va_list, printf_opt_t *);
void printf_print_float(const char **, char **, va_list, printf_opt_t *);
##
## Makefile for libmy in /mnt/data/Delivery/Perso/libmy
##
## Made by Benoit Lormeau
## Login   <benoit.lormeau@epitech.eu>
##
## Started on  Mon Oct 23 10:11:27 2017 Benoit Lormeau
## Last update Tue Nov 14 11:49:06 2017 Benoit Lormeau
##

RM	=	rm -rf

SRC	=	Sources
INCLUDE	=	-IIncludes

CFLAGS	+=	-W -Wall -Wextra -g3
CFLAGS	+=	$(INCLUDE)


# ----------------------------------------------------- #
#  Modules                                              #
# ----------------------------------------------------- #

Char	=	$(SRC)/Char/is_alnum.c			\
		$(SRC)/Char/is_alpha.c			\
		$(SRC)/Char/is_blank.c			\
		$(SRC)/Char/is_cntrl.c			\
		$(SRC)/Char/is_digit.c			\
		$(SRC)/Char/is_graph.c			\
		$(SRC)/Char/is_lower.c			\
		$(SRC)/Char/is_print.c			\
		$(SRC)/Char/is_punct.c			\
		$(SRC)/Char/is_space.c			\
		$(SRC)/Char/is_upper.c			\
		$(SRC)/Char/is_xdigit.c			\
		$(SRC)/Char/to_lower.c			\
		$(SRC)/Char/to_upper.c

FS	=	$(SRC)/FS/file_get_contents.c		\
		$(SRC)/FS/file_get_lines.c		\
		$(SRC)/FS/file_is.c			\
		$(SRC)/FS/file_put_contents.c		\
		$(SRC)/FS/scandir.c

IO	=	$(SRC)/IO/printf/asprintf.c		\
		$(SRC)/IO/printf/dprintf.c		\
		$(SRC)/IO/printf/printf.c		\
		$(SRC)/IO/printf/sprintf.c		\
		$(SRC)/IO/printf/printf_opt.c		\
		$(SRC)/IO/printf/printf_print.c		\
		$(SRC)/IO/printf/printf_process.c	\
		$(SRC)/IO/gnl.c				\
		$(SRC)/IO/putchar.c			\
		$(SRC)/IO/putnbr.c			\
		$(SRC)/IO/puts.c			\
		$(SRC)/IO/putstr.c

Math	=	$(SRC)/Math/angle.c			\
		$(SRC)/Math/ceil.c			\
		$(SRC)/Math/floor.c			\
		$(SRC)/Math/pow.c			\
		$(SRC)/Math/rand.c			\
		$(SRC)/Math/round.c

Memory	=	$(SRC)/Memory/calloc.c			\
		$(SRC)/Memory/malloc.c			\
		$(SRC)/Memory/memcpy.c			\
		$(SRC)/Memory/memdup.c			\
		$(SRC)/Memory/memmove.c			\
		$(SRC)/Memory/memset.c			\
		$(SRC)/Memory/realloc.c

Numeric	=	$(SRC)/Numeric/atoi.c			\
		$(SRC)/Numeric/atou.c			\
		$(SRC)/Numeric/dtoa.c			\
		$(SRC)/Numeric/intlen.c			\
		$(SRC)/Numeric/itoa.c			\
		$(SRC)/Numeric/utoa.c

Regex	=	$(SRC)/Regex/capture.c			\
		$(SRC)/Regex/match.c			\
		$(SRC)/Regex/replace.c			\
		$(SRC)/Regex/split.c

String	=	$(SRC)/String/explode.c			\
		$(SRC)/String/implode.c			\
		$(SRC)/String/str_apd.c			\
		$(SRC)/String/str_casecmp.c		\
		$(SRC)/String/str_cat.c			\
		$(SRC)/String/str_chr.c			\
		$(SRC)/String/str_cmp.c			\
		$(SRC)/String/str_cpy.c			\
		$(SRC)/String/str_dup.c			\
		$(SRC)/String/str_empty.c		\
		$(SRC)/String/str_len.c			\
		$(SRC)/String/str_pad.c			\
		$(SRC)/String/str_pos.c			\
		$(SRC)/String/str_ppd.c			\
		$(SRC)/String/str_repeat.c		\
		$(SRC)/String/str_replace.c		\
		$(SRC)/String/str_rev.c			\
		$(SRC)/String/str_sep.c			\
		$(SRC)/String/str_str.c			\
		$(SRC)/String/str_tolower.c		\
		$(SRC)/String/str_toupper.c


## Comment a line if you don't want a module.
## Careful about dependencies though

SRCS	+=	$(Char)
SRCS	+=	$(FS)
SRCS	+=	$(IO)
SRCS	+=	$(Math)
SRCS	+=	$(Memory)
SRCS	+=	$(Numeric)
SRCS	+=	$(Regex)
SRCS	+=	$(String)


OBJS	=	$(SRCS:.c=.o)

NAME	=	libmy.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

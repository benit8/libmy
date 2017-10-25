##
## Makefile for libmy in /mnt/data/Delivery/Perso/libmy
##
## Made by Benoit Lormeau
## Login   <benoit.lormeau@epitech.eu>
##
## Started on  Mon Oct 23 10:11:27 2017 Benoit Lormeau
## Last update Mon Oct 23 10:11:27 2017 Benoit Lormeau
##

RM	=	rm -rf

SRC	=	Sources
INCLUDE	=	-IIncludes/

CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	$(INCLUDE)

SRCS	=	$(SRC)/Char/is_alnum.c			\
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
		$(SRC)/Char/to_upper.c			\
		$(SRC)/FS/file.c			\
		$(SRC)/FS/file_executable.c		\
		$(SRC)/FS/file_exists.c			\
		$(SRC)/FS/file_get_contents.c		\
		$(SRC)/FS/file_put_contents.c		\
		$(SRC)/FS/file_readable.c		\
		$(SRC)/FS/file_writable.c		\
		$(SRC)/FS/scandir.c			\
		$(SRC)/IO/gnl.c				\
		$(SRC)/IO/putchar.c			\
		$(SRC)/IO/putnbr.c			\
		$(SRC)/IO/puts.c			\
		$(SRC)/IO/putstr.c			\
		$(SRC)/Math/max.c			\
		$(SRC)/Math/min.c			\
		$(SRC)/Memory/calloc.c			\
		$(SRC)/Memory/malloc.c			\
		$(SRC)/Memory/memcpy.c			\
		$(SRC)/Memory/memdup.c			\
		$(SRC)/Memory/memset.c			\
		$(SRC)/Memory/realloc.c			\
		$(SRC)/Numeric/abs.c			\
		$(SRC)/Numeric/atoi.c			\
		$(SRC)/Numeric/atou.c			\
		$(SRC)/Numeric/intlen.c			\
		$(SRC)/Numeric/itoa.c			\
		$(SRC)/Numeric/uintlen.c		\
		$(SRC)/Numeric/utoa.c			\
		$(SRC)/Regex/capture.c			\
		$(SRC)/Regex/match.c			\
		$(SRC)/Regex/replace.c			\
		$(SRC)/Regex/split.c			\
		$(SRC)/String/explode.c			\
		$(SRC)/String/implode.c			\
		$(SRC)/String/str_apd.c			\
		$(SRC)/String/str_casecmp.c		\
		$(SRC)/String/str_cat.c			\
		$(SRC)/String/str_cmp.c			\
		$(SRC)/String/str_cpy.c			\
		$(SRC)/String/str_dup.c			\
		$(SRC)/String/str_empty.c		\
		$(SRC)/String/str_len.c			\
		$(SRC)/String/str_pad.c			\
		$(SRC)/String/str_pos.c			\
		$(SRC)/String/str_repeat.c		\
		$(SRC)/String/str_replace.c		\
		$(SRC)/String/str_rev.c			\
		$(SRC)/String/str_sep.c			\
		$(SRC)/String/str_str.c

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

test:
	gcc main.c -g3 $(CFLAGS) -L./ -lmy

.PHONY: all clean fclean re test
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
		$(SRC)/Display/putchar.c		\
		$(SRC)/Display/putnbr.c			\
		$(SRC)/Display/putstr.c			\
		$(SRC)/Display/puts.c			\
		$(SRC)/FS/file_executable.c		\
		$(SRC)/FS/file_exists.c			\
		$(SRC)/FS/file_get_contents.c		\
		$(SRC)/FS/file_put_contents.c		\
		$(SRC)/FS/file_readable.c		\
		$(SRC)/FS/file_writable.c		\
		$(SRC)/FS/scandir.c			\
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
		$(SRC)/String/strcasecmp.c		\
		$(SRC)/String/strcat.c			\
		$(SRC)/String/strcmp.c			\
		$(SRC)/String/strcpy.c			\
		$(SRC)/String/strdup.c			\
		$(SRC)/String/strlen.c			\
		$(SRC)/String/strncasecmp.c		\
		$(SRC)/String/strncat.c			\
		$(SRC)/String/strncmp.c			\
		$(SRC)/String/strncpy.c			\
		$(SRC)/String/strnlen.c			\
		$(SRC)/String/strrev.c			\
		$(SRC)/String/strsep.c			\
		$(SRC)/String/strstr.c

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
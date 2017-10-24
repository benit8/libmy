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

SRCS	=	$(SRC)/Display/getnbr.c			\
		$(SRC)/Display/putchar.c		\
		$(SRC)/Display/putnbr.c			\
		$(SRC)/Display/putstr.c			\
		$(SRC)/Display/puts.c			\
		$(SRC)/FS/file_get_contents.c		\
		$(SRC)/FS/scandir.c			\
		$(SRC)/Memory/calloc.c			\
		$(SRC)/Memory/malloc.c			\
		$(SRC)/Memory/memcpy.c			\
		$(SRC)/Memory/memdup.c			\
		$(SRC)/Memory/memset.c			\
		$(SRC)/Memory/realloc.c			\
		$(SRC)/Regex/capture.c			\
		$(SRC)/Regex/count.c			\
		$(SRC)/Regex/match.c			\
		$(SRC)/Regex/replace.c			\
		$(SRC)/Regex/split.c			\
		$(SRC)/String/explode.c			\
		$(SRC)/String/strcat.c			\
		$(SRC)/String/strcmp.c			\
		$(SRC)/String/strcpy.c			\
		$(SRC)/String/strdup.c			\
		$(SRC)/String/strlen.c			\
		$(SRC)/String/strncat.c			\
		$(SRC)/String/strncmp.c			\
		$(SRC)/String/strncpy.c			\
		$(SRC)/String/strnlen.c			\
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
	gcc main.c -g3 $(CFLAGS) $(INCLUDE) -L./ -lmy

.PHONY: all clean fclean re test
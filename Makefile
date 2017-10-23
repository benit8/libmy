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

CFLAGS	+=	-I./
CFLAGS	+=	-W -Wall -Wextra

SRCS	=	fs/scandir.c			\
		fs/file_get_contents.c		\
		mem/calloc.c			\
		mem/malloc.c			\
		mem/memcpy.c			\
		mem/memdup.c			\
		mem/memset.c			\
		mem/realloc.c			\
		puts/getnbr.c			\
		puts/putchar.c			\
		puts/putnbr.c			\
		puts/putstr.c			\
		puts/puts.c			\
		regex/capture.c			\
		regex/count.c			\
		regex/match.c			\
		regex/replace.c			\
		regex/split.c			\
		string/strcat.c			\
		string/strcmp.c			\
		string/strcpy.c			\
		string/strdup.c			\
		string/strlen.c			\
		string/strncat.c		\
		string/strncmp.c		\
		string/strncpy.c		\
		string/strnlen.c		\
		string/strstr.c

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
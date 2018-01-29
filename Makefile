##
## EPITECH PROJECT, 2018
## libmy
## File description:
## Makefile
##

RM	=	rm -f

SRC	=	sources
INCLUDE	=	-Iincludes

CFLAGS	+=	$(INCLUDE)
CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-g3


# ----------------------------------------------------- #
#  Modules                                              #
# ----------------------------------------------------- #

Char	=	$(SRC)/char/is_alnum.c			\
		$(SRC)/char/is_alpha.c			\
		$(SRC)/char/is_blank.c			\
		$(SRC)/char/is_cntrl.c			\
		$(SRC)/char/is_digit.c			\
		$(SRC)/char/is_graph.c			\
		$(SRC)/char/is_lower.c			\
		$(SRC)/char/is_print.c			\
		$(SRC)/char/is_punct.c			\
		$(SRC)/char/is_space.c			\
		$(SRC)/char/is_upper.c			\
		$(SRC)/char/is_xdigit.c			\
		$(SRC)/char/to_lower.c			\
		$(SRC)/char/to_upper.c

DSA	=	$(SRC)/dsa/list/access.c		\
		$(SRC)/dsa/list/capacity.c		\
		$(SRC)/dsa/list/list.c			\
		$(SRC)/dsa/list/modifiers.c		\
		$(SRC)/dsa/list/modifiers_pushpop.c	\
		$(SRC)/dsa/list/operations.c		\
		$(SRC)/dsa/queue/access.c		\
		$(SRC)/dsa/queue/capacity.c		\
		$(SRC)/dsa/queue/modifiers.c		\
		$(SRC)/dsa/queue/queue.c		\
		$(SRC)/dsa/stack/access.c		\
		$(SRC)/dsa/stack/capacity.c		\
		$(SRC)/dsa/stack/modifiers.c		\
		$(SRC)/dsa/stack/stack.c		\
		$(SRC)/dsa/table/foreach.c		\
		$(SRC)/dsa/table/get.c			\
		$(SRC)/dsa/table/set.c			\
		$(SRC)/dsa/table/table.c		\
		$(SRC)/dsa/table/tests.c		\
		$(SRC)/dsa/sort.c

FS	=	$(SRC)/fs/file_get_contents.c		\
		$(SRC)/fs/file_get_lines.c		\
		$(SRC)/fs/file_is.c			\
		$(SRC)/fs/file_put_contents.c		\
		$(SRC)/fs/scandir.c			\
		$(SRC)/fs/scandir_sort.c

IO	=	$(SRC)/io/printf/asprintf.c		\
		$(SRC)/io/printf/dprintf.c		\
		$(SRC)/io/printf/printf.c		\
		$(SRC)/io/printf/sprintf.c		\
		$(SRC)/io/printf/printf_opt.c		\
		$(SRC)/io/printf/printf_print.c		\
		$(SRC)/io/printf/printf_process.c	\
		$(SRC)/io/gnl.c				\
		$(SRC)/io/putchar.c			\
		$(SRC)/io/putnbr.c			\
		$(SRC)/io/puts.c			\
		$(SRC)/io/putstr.c

Math	=	$(SRC)/math/angle.c			\
		$(SRC)/math/ceil.c			\
		$(SRC)/math/exp.c			\
		$(SRC)/math/floor.c			\
		$(SRC)/math/fmod.c			\
		$(SRC)/math/frexp.c			\
		$(SRC)/math/log.c			\
		$(SRC)/math/pow.c			\
		$(SRC)/math/rand.c			\
		$(SRC)/math/round.c

Memory	=	$(SRC)/memory/calloc.c			\
		$(SRC)/memory/malloc.c			\
		$(SRC)/memory/memcmp.c			\
		$(SRC)/memory/memcpy.c			\
		$(SRC)/memory/memdup.c			\
		$(SRC)/memory/memmove.c			\
		$(SRC)/memory/memset.c			\
		$(SRC)/memory/realloc.c

Numeric	=	$(SRC)/numeric/atof.c			\
		$(SRC)/numeric/atoi.c			\
		$(SRC)/numeric/atou.c			\
		$(SRC)/numeric/ftoa.c			\
		$(SRC)/numeric/intlen.c			\
		$(SRC)/numeric/itoa.c			\
		$(SRC)/numeric/strtol.c			\
		$(SRC)/numeric/utoa.c

Parsing	=	$(SRC)/parsing/calc/calc.c		\
		$(SRC)/parsing/calc/expression.c	\
		$(SRC)/parsing/calc/infix.c		\
		$(SRC)/parsing/calc/postfix.c		\
		$(SRC)/parsing/ini/array.c		\
		$(SRC)/parsing/ini/data.c		\
		$(SRC)/parsing/ini/get.c		\
		$(SRC)/parsing/ini/line.c		\
		$(SRC)/parsing/ini/parse.c		\
		$(SRC)/parsing/ini/section.c		\
		$(SRC)/parsing/ini/toolbox.c		\
		$(SRC)/parsing/ini/var.c		\
		$(SRC)/parsing/var.c

Regex	=	$(SRC)/regex/capture.c			\
		$(SRC)/regex/match.c			\
		$(SRC)/regex/replace.c			\
		$(SRC)/regex/split.c

String	=	$(SRC)/string/explode.c			\
		$(SRC)/string/implode.c			\
		$(SRC)/string/str_apd.c			\
		$(SRC)/string/str_casecmp.c		\
		$(SRC)/string/str_cat.c			\
		$(SRC)/string/str_chr.c			\
		$(SRC)/string/str_cmp.c			\
		$(SRC)/string/str_cpy.c			\
		$(SRC)/string/str_cspn.c		\
		$(SRC)/string/str_dup.c			\
		$(SRC)/string/str_empty.c		\
		$(SRC)/string/str_len.c			\
		$(SRC)/string/str_match.c		\
		$(SRC)/string/str_natcmp.c		\
		$(SRC)/string/str_natcasecmp.c		\
		$(SRC)/string/str_pad.c			\
		$(SRC)/string/str_pos.c			\
		$(SRC)/string/str_ppd.c			\
		$(SRC)/string/str_repeat.c		\
		$(SRC)/string/str_replace.c		\
		$(SRC)/string/str_rev.c			\
		$(SRC)/string/str_sep.c			\
		$(SRC)/string/str_str.c			\
		$(SRC)/string/str_tolower.c		\
		$(SRC)/string/str_toupper.c		\
		$(SRC)/string/str_trim.c


# Comment a line if you don't want a module.
# Be careful about dependencies though (see below)

SRCS	+=	$(Char)
SRCS	+=	$(DSA)
SRCS	+=	$(FS)
SRCS	+=	$(IO)
SRCS	+=	$(Math)
SRCS	+=	$(Memory)
SRCS	+=	$(Numeric)
# SRCS	+=	$(Parsing)
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



#    +---------------------------------------------------------------------+
#    | Dependencies                                                        |
#    +---------+-----------------------------------------------------------+
# -> | Char    |                                                           |
#    +---------+-----------------------------------------------------------+
# -> | DSA     | Memory / String                                           |
#    +---------+-----------------------------------------------------------+
# -> | FS      | Memory / String                                           |
#    +---------+-----------------------------------------------------------+
# -> | IO      | Numeric / String                                          |
#    +---------+-----------------------------------------------------------+
# -> | Math    |                                                           |
#    +---------+-----------------------------------------------------------+
# -> | Memory  |                                                           |
#    +---------+-----------------------------------------------------------+
# -> | Numeric | Char / Math / Memory / String                             |
#    +---------+-----------------------------------------------------------+
# -> | Parsing | Char / DSA / FS / IO / Memory / Numeric / String          |
#    +---------+-----------------------------------------------------------+
# -> | Regex   | Memory / String                                           |
#    +---------+-----------------------------------------------------------+
# -> | String  | Char / Math / Memory / Numeric                            |
#    +---------+-----------------------------------------------------------+
##
## EPITECH PROJECT, 2018
## libmy
## File description:
## Makefile
##

PROJECT	=	Libmy UT
NAME	=	tests

SRC_DIR	=	src/

OBJS	=	$(SRCS:.c=.o)

################################################################################

# ---------------------------------------------------------------------------- #
#  Modules                                                                     #
# ---------------------------------------------------------------------------- #

Char	=	char/is_alnum.c			\
		char/is_alpha.c			\
		char/is_blank.c			\
		char/is_cntrl.c			\
		char/is_digit.c			\
		char/is_graph.c			\
		char/is_lower.c			\
		char/is_print.c			\
		char/is_punct.c			\
		char/is_space.c			\
		char/is_upper.c			\
		char/is_xdigit.c		\
		char/to_lower.c			\
		char/to_upper.c

DSA	=	dsa/list/access.c		\
		dsa/list/capacity.c		\
		dsa/list/list.c			\
		dsa/list/modifiers.c		\
		dsa/list/modifiers_pushpop.c	\
		dsa/list/operations.c		\
		dsa/map/access.c		\
		dsa/map/capacity.c		\
		dsa/map/map.c			\
		dsa/map/modifiers.c		\
		dsa/map/operations.c		\
		dsa/queue/access.c		\
		dsa/queue/capacity.c		\
		dsa/queue/modifiers.c		\
		dsa/queue/queue.c		\
		dsa/stack/access.c		\
		dsa/stack/capacity.c		\
		dsa/stack/modifiers.c		\
		dsa/stack/stack.c		\
		dsa/sort.c

FS	=	fs/file_get_contents.c		\
		fs/file_get_lines.c		\
		fs/file_is.c			\
		fs/file_put_contents.c		\
		fs/filesize.c			\
		fs/is_file.c			\
		fs/scandir.c			\
		fs/scandir_sort.c

IO	=	io/log/data.c			\
		io/log/file.c			\
		io/log/level.c			\
		io/log/loggers.c		\
		io/log/program_name.c		\
		io/log/write.c			\
		io/printf/asprintf.c		\
		io/printf/dprintf.c		\
		io/printf/fprintf.c		\
		io/printf/printf.c		\
		io/printf/sprintf.c		\
		io/printf/printf_opt.c		\
		io/printf/printf_print.c	\
		io/printf/printf_process.c	\
		io/getdelim.c			\
		io/gnl.c			\
		io/putchar.c			\
		io/putnbr.c			\
		io/puts.c			\
		io/putstr.c

Math	=	math/angle.c			\
		math/ceil.c			\
		math/exp.c			\
		math/floor.c			\
		math/fmod.c			\
		math/frexp.c			\
		math/ldexp.c			\
		math/log.c			\
		math/pow.c			\
		math/rand.c			\
		math/round.c			\
		math/sqrt.c

Memory	=	memory/calloc.c			\
		memory/malloc.c			\
		memory/memcmp.c			\
		memory/memcpy.c			\
		memory/memdup.c			\
		memory/memmove.c		\
		memory/memset.c			\
		memory/realloc.c

Numeric	=	numeric/atof.c			\
		numeric/atoi.c			\
		numeric/atou.c			\
		numeric/ftoa.c			\
		numeric/intlen.c		\
		numeric/itoa.c			\
		numeric/strtol.c		\
		numeric/utoa.c

Parsing	=	parsing/calc.c

Regex	=	regex/capture.c			\
		regex/match.c			\
		regex/replace.c			\
		regex/split.c

String	=	string/explode.c		\
		string/implode.c		\
		string/strapd.c			\
		string/strcasecmp.c		\
		string/strcat.c			\
		string/strchr.c			\
		string/strcmp.c			\
		string/strcpy.c			\
		string/strdup.c			\
		string/strempty.c		\
		string/strlen.c			\
		string/strmatch.c		\
		string/strnatcasecmp.c		\
		string/strnatcmp.c		\
		string/strpad.c			\
		string/strpos.c			\
		string/strppd.c			\
		string/strrepeat.c		\
		string/strreplace.c		\
		string/strrev.c			\
		string/strsep.c			\
		string/strspn.c			\
		string/strstr.c			\
		string/strtolower.c		\
		string/strtoupper.c		\
		string/strtrim.c


SRCS	+=	$(addprefix $(SRC_DIR),$(Char))
# SRCS	+=	$(addprefix $(SRC_DIR),$(DSA))
# SRCS	+=	$(addprefix $(SRC_DIR),$(FS))
# SRCS	+=	$(addprefix $(SRC_DIR),$(IO))
SRCS	+=	$(addprefix $(SRC_DIR),$(Math))
SRCS	+=	$(addprefix $(SRC_DIR),$(Memory))
# SRCS	+=	$(addprefix $(SRC_DIR),$(Numeric))
SRCS	+=	$(addprefix $(SRC_DIR),$(Parsing))
SRCS	+=	$(addprefix $(SRC_DIR),$(Regex))
# SRCS	+=	$(addprefix $(SRC_DIR),$(String))


################################################################################

CFLAGS	+=	-g3
CFLAGS	+=	-I../includes
CFLAGS	+=	-W -Wall -Wextra

LDFLAGS	+=	-L.. -lmy
LDFLAGS	+=	-lm
LDFLAGS	+=	-lcriterion

################################################################################

SHELL	=	/bin/bash
PRINT	=	printf "$(PROJECT):  " ; printf
CC	=	gcc

RESET	=	\033[0m
RED	=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
MAGENTA	=	\033[0;35m
CYAN	=	\033[1;36m

################################################################################

all: $(NAME)

$(NAME): prebuild $(OBJS)
	@ $(PRINT) "$(YELLOW)Building project binary$(RESET)\n"
	@ $(PRINT) "  [  ]  $(BLUE)%b$(RESET)\\r" $(NAME)
	@ $(CC) -o $(NAME) $(OBJS) $(LDFLAGS) && \
	  ($(PRINT) "  [$(GREEN)OK$(RESET)]  $(CYAN)%b$(RESET)\n" $(NAME) ; exit 0) || \
	  ($(PRINT) "  [$(RED)XX$(RESET)]  $(CYAN)%b$(RESET)\n" $(NAME) ; exit 1)

prebuild:
	@ $(PRINT) "$(YELLOW)%b$(RESET)\n" "Compiling source files"

clean:
	@ $(PRINT) "$(YELLOW)%-40b$(RESET)" "Deleting object files"
	@ $(RM) $(OBJS)
	@ printf "$(GREEN)Done$(RESET)\n"

fclean: clean
	@ $(PRINT) "$(YELLOW)%-40b$(RESET)" "Deleting $(NAME)"
	@ $(RM) $(NAME)
	@ printf "$(GREEN)Done$(RESET)\n"

re: fclean all

.c.o:
	@ $(PRINT) "  [  ]  $(CYAN)%b$(RESET)\\r" $<
	@ $(CC) -c $< -o $@ $(CFLAGS) && \
	  ($(PRINT) "  [$(GREEN)OK$(RESET)]  $(CYAN)%b$(RESET)\n" $<) || \
	  ($(PRINT) "  [$(RED)XX$(RESET)]  $(CYAN)%b$(RESET)\n" $< ; exit 1)

.PHONY: all $(NAME) prebuild clean fclean re .c.o
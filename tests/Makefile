CFLAGS	+=	-I../includes
CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-g3

LDFLAGS	+=	-L.. -lmy


SRCS	=	main.c

OBJS	=	$(SRCS:.c=.o)

all: $(OBJS)
	gcc -o a.out $(OBJS) $(LDFLAGS)
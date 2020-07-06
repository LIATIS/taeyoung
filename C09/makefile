SRCS = main.c fct.c

OBJS = ${SRCS:.c=.o}

NAME = hello

CC	= cc

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			cc -o hello &{OBJS}

all:		${NAME}

clean:
			rm ${OBJS}	
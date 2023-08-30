NAME	=	pipex
SRCS	=	src/main.c src/parser.c src/utils.c\
			src/cmds.c src/files.c
LIBFT	=	./includes/libft
CC		=	cc
RM		=	rm -rf
CFLAGS	=	-Wall -Wextra -Werror 

all : ${LIBFT} ${NAME}

${NAME} : ${LIBFT} ${SRCS}
		${CC} ${CFLAGS} ${SRCS} includes/libft/libft.a -o ${NAME}

${LIBFT}:
		${MAKE} -C $@

clean :
		${MAKE} clean -C ${LIBFT}

fclean : clean
		${RM} ${NAME}
		${MAKE} fclean -C ${LIBFT}
		
re :	fclean all

.PHONY: all clean fclean re ${LIBFT}
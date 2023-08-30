UNAME_S := $(shell uname -s)
NAME	=	libft.a
SRC		=	ft_printf.c ft_printf_c.c ft_printf_signed.c ft_printf_unsigned.c \
			ft_printf_s_mac.c ft_printf_p_mac.c ft_printf_spec_parser.c ft_printf_util.c\
			ft_printf_util2.c ft_printf_prcnt_mac.c\
			ft_atoi.c ft_isalpha.c  ft_itoa.c ft_itoa_ll.c ft_itoa_ull.c ft_strjoin.c ft_memmove.c\
			ft_putnbr_fd.c  ft_memcpy.c ft_strlcpy.c ft_striteri.c ft_str_tolower.c ft_tolower.c\
			ft_bzero.c ft_isascii.c ft_memchr.c  ft_memset.c ft_putstr_fd.c\
			ft_strlen.c ft_strrchr.c ft_toupper.c ft_strnstr.c ft_calloc.c\
			ft_isdigit.c ft_memcmp.c ft_putchar_fd.c ft_split.c ft_atoi_l.c\
			ft_strmapi.c ft_strtrim.c ft_isalnum.c ft_isprint.c ft_strdup.c\
			ft_putendl_fd.c ft_strchr.c ft_strlcat.c ft_strncmp.c ft_substr.c\
			ft_strcmp.c ft_strcpy.c ft_strcat.c ft_strncpy.c ft_isspace.c ft_split_quotes.c\
			ft_putstr.c ft_putnbr_ll.c ft_putnbr_ull.c ft_itoa_oct.c ft_itoa_hex.c
ifeq ($(UNAME_S),Linux)
	SRC		=	ft_printf.c ft_printf_c.c ft_printf_signed.c ft_printf_unsigned.c \
			ft_printf_s.c ft_printf_p.c ft_printf_spec_parser.c ft_printf_util.c\
			ft_printf_util2.c ft_printf_prcnt.c\
			ft_atoi.c ft_isalpha.c  ft_itoa.c ft_itoa_ll.c ft_itoa_ull.c ft_strjoin.c ft_memmove.c\
			ft_putnbr_fd.c  ft_memcpy.c ft_strlcpy.c ft_striteri.c ft_str_tolower.c ft_tolower.c\
			ft_bzero.c ft_isascii.c ft_memchr.c  ft_memset.c ft_putstr_fd.c\
			ft_strlen.c ft_strrchr.c ft_toupper.c ft_strnstr.c ft_calloc.c\
			ft_isdigit.c ft_memcmp.c ft_putchar_fd.c ft_split.c ft_atoi_l.c\
			ft_strmapi.c ft_strtrim.c ft_isalnum.c ft_isprint.c ft_strdup.c\
			ft_putendl_fd.c ft_strchr.c ft_strlcat.c ft_strncmp.c ft_substr.c\
			ft_strcmp.c ft_strcpy.c ft_strcat.c ft_strncpy.c ft_isspace.c ft_split_quotes.c\
			ft_putstr.c ft_putnbr_ll.c ft_putnbr_ull.c ft_itoa_oct.c ft_itoa_hex.c\
			get_next_line.c get_next_line_utils.c
endif

OBJ		=	${SRC:.c=.o}
LIBC	=	ar	-rc
CC		=	cc
RM		=	rm -rf
CFLAGS	=	-Wall -Wextra -Werror 

all : ${NAME}

${NAME} : ${OBJ}
		${LIBC} ${NAME} ${OBJ}

# ${OBJ}	:
# 		${CC} ${CFLAGS} -c ${SRC}

clean :
		${RM} ${OBJ}

fclean : clean
		${RM} ${NAME}
		
re :	fclean all

.PHONY: all clean fclean re
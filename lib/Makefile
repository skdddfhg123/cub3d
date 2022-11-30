NAME			=	dmcw.a

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra

AR				=	ar
ARFLAGS			=	-rcs

INCLUDES_DIR	=	include
LIBFT_DIR		=	src/libft
GNL_DIR			=	src/get_next_line

LIBFT			=	./ft_bzero.c ./ft_memcpy.c ./ft_memset.c ./ft_memccpy.c \
	./ft_memchr.c ./ft_memcmp.c ./ft_strlen.c ./ft_isalpha.c ./ft_isdigit.c \
	./ft_isalnum.c ./ft_isascii.c ./ft_isprint.c ./ft_tolower.c ./ft_toupper.c \
	./ft_strchr.c ./ft_strrchr.c ./ft_strncmp.c ./ft_strlcpy.c ./ft_atoi.c \
	./ft_itoa.c ./ft_memmove.c ./ft_putchar_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c \
	./ft_putstr_fd.c ./ft_split.c ./ft_strdup.c ./ft_strjoin.c ./ft_strmapi.c \
	./ft_substr.c ./ft_strtrim.c ./ft_calloc.c ./ft_strnstr.c ./ft_strlcat.c \
	./ft_lstnew.c ./ft_lstadd_front.c ./ft_lstadd_back.c ./ft_lstsize.c \
	./ft_lstlast.c ./ft_lstdelone.c ./ft_lstclear.c ./ft_lstiter.c

GNL				=	get_next_line.c get_next_line_utils.c

all: $(NAME)

$(NAME): libft gnl

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $^
	@$(AR) $(ARFLAGS) $(NAME) $@

libft: $(addprefix $(LIBFT_DIR)/, $(LIBFT:.c=.o))
gnl: $(addprefix $(GNL_DIR)/, $(GNL:.c=.o))

clean:
	@rm -rf $(addprefix $(LIBFT_DIR)/, $(LIBFT:.c=.o))
	@rm -rf $(addprefix $(GNL_DIR)/, $(GNL:.c=.o))

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

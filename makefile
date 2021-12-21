NAME		=	minishell

HEADER		=	./includes/

CC			=	gcc

FLAGS		=	-g -Werror -Wall -Wextra -I $(HEADER)

SRCS		=	srcs/minishell.c \
			srcs/built_in.c \
			srcs/built_in_utils.c \

OBJS		=	$(SRCS:.c=.o)

.c.o		:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all		:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean		:
			rm -rf $(OBJS)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean all

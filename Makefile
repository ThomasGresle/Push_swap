NAME		=	push_swap

HEADER		=	./includes/

CC			=	clang

FLAGS		=	-g -Werror -Wall -Wextra -I $(HEADER)

SRCS		=	srcs/change_list.c \
			srcs/check.c \
			srcs/create_list.c \
			srcs/free.c \
			srcs/ft_atoi.c \
			srcs/ft_atoi_check.c \
			srcs/ft_split.c \
			srcs/push_swap.c \
			srcs/utils.c \
			srcs/set_begin_sort.c \
			srcs/sorting_by_bigger.c \
			srcs/sorting_by_link.c \
			srcs/create_list_2.c \
			srcs/sorting_utils.c \
			srcs/sorting_utils_2.c \
			srcs/move_utils.c \
			srcs/sorting_list_b.c \
			srcs/rotation.c \

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

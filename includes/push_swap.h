#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct			s_list_number
{
	int					number;
	int			    	no_move;
	int		    		order;
	struct s_list_number*previous;
	struct s_list_number*next;
}						t_list_number;

typedef struct			s_list
{
	t_list_number		*first;
	int		    		keep_a;
	int		    		size;
	t_list_number		*begin_sort;
}						t_list;

typedef struct			s_move
{
	char				*move;
	struct s_move		*next;
}						t_move;

typedef struct			s_move_list
{
	int			    	move_nbr;
	t_move				*first_move;
}						t_move_list;

typedef struct			s_swap
{
	t_list_number		*a_nbr;
	t_list_number		*b_nbr;
	int					a_rotation;
	int					b_rotation;
	int		    		size;
	int 				no_move;
}						t_swap;

int				first_check(t_list *list);
void		    ft_putstr(char *str);
int				ft_strlen(const char *str);
void			free_list(t_list *list);
void			free_move_list(t_move_list *list);
int				ft_atoi(const char *str);
int				ft_atoi_check(const char *str, int *error);
char			**ft_split(char const *s, char c);
void			free_array(char **mat);
t_list_number	*create_number(int number);
void			add_number(t_list *list, t_list_number *number);
t_list			*create_list(int ac, char **av);
void			order_list(t_list *list);
void			set_begin_sort_bigger(t_list *list);
void			set_begin_sort_link(t_list *list);
t_move_list		*sort_by_bigger(t_list *list_a);
t_move_list		*sort_by_link(t_list *list_a);
t_list			*create_list_b(void);
t_move_list		*create_move_list(void);
int				is_move_to_b(t_list *list_a);
t_move			*create_move(char *move);
void			move_s(t_list *list, char *move, t_move_list *move_list);
void			move_p(t_list *dest, t_list *src, char *move, t_move_list *list);
void			move_r(t_list *list, char *move, t_move_list *move_list);
void			move_rr(t_list *list, char *move, t_move_list *move_list);
int				number_keep_a_bigger(t_list *list, t_list_number *begin_sort);
int				number_keep_a_link(t_list *list, t_list_number *begin_sort);
void			put_to(t_list *list, t_list_number *number);
t_list_number	*take_from(t_list *list);
t_swap			*create_swap(void);
void			sort_list_b(t_list *list_a, t_list *list_b, t_move_list *move_list);
void			choose_rotation(t_list *list_a, t_list *list_b, t_swap *swap);
int				pick_max(int i, int j);
void			move_r_all(t_list *list_a, t_list *list_b, char *move, t_move_list *move_list);
void			move_rr_all(t_list *list_a, t_list *list_b, char *move, t_move_list *move_list);
void			finish_list_a(t_list *list_a, t_move_list *move_list);
char			*ft_strdup(char *s1);
void			add_move(t_move_list *list, t_move *move);


# endif
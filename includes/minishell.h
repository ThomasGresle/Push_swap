#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <sys/types.h>
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
void    ft_putstr(char *str);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char *s1, char const *s2);
void    exec_exit(char **av);
void    error_args(int i);
void    exec_echo(char **av);
void    exec_pwd(char **av);
char    *exec_cd(char **av);

# endif
#include "../includes/minishell.h"

void    exec_exit(char **av)
{
    if (av[2])
        error_args(1);
    else
        ft_putstr("exit\n");
}

void    exec_echo_flag(char **av)
{
    ft_putstr(av[3]);
}

void    exec_echo(char **av)
{
    if (!(av[2]))
        error_args(0);
    else
    {
        if (ft_strncmp(av[2], "-n", 3) == 0)
        {
            if (!(av[3]))
                error_args(0);
            else if (av[4])
                error_args(1);
            else
                exec_echo_flag(av);
        }
        else
        {
            if (av[3])
                error_args(1);
            else
            {
                ft_putstr(av[2]);
                ft_putstr("\n");
            }
        }
    }
}

void    exec_pwd(char **av)
{
    char *loc;

    loc = 0;
    loc = malloc(sizeof(char) * 1024);
    if (av[2])
        error_args(1);
    else
    {
        if (getcwd(loc, 1024) != NULL)
        {
            ft_putstr(loc);
            ft_putstr("\n");
        }
        else
            ft_putstr("Error\n");
    }
}

char    *exec_cd(char **av)
{
    char *path;

    path = 0;
    if (av[3])
    {
        error_args(1);
        return (path);
    }
    else
    {
        path = malloc(sizeof(char) * 1024);
        if (av[2] && av[2][0] && av[2][1] && av[2][1] != '/' && av[2][1] != '~')
        {
            if (getcwd(path, 1024) != NULL)
            {
                path = ft_strjoin(path, "/");
                path = ft_strjoin(path, av[2]);
                if (chdir(path) == -1)
                {
                    ft_putstr("Error\n");
                    return (0);
                }
                else
                    return (path);
            }
            else
            {
                ft_putstr("Error\n");
                return (path);
            }
        }
        else
        {
            path = ft_strjoin(path, av[2]);
            return (path);
        }
    }
}

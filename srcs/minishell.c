#include "../includes/minishell.h"

void    clean_all()
{

}

void    parse_built_in(char **av, char *path)
{
    int i;

    i = 0;
    if (av && av[1] && (ft_strncmp(av[1], "echo", 4) == 0 ||
        ft_strncmp(av[1], "pwd", 3) == 0 || ft_strncmp(av[1], "cd", 2) == 0
        || ft_strncmp(av[1], "export", 6) == 0 || ft_strncmp(av[1], "unset", 5) == 0
        || ft_strncmp(av[1], "env", 3) == 0))
    {
        if (ft_strncmp(av[1], "exit", 4) == 0)
            exec_exit(av);
        else if (ft_strncmp(av[1], "echo", 4) == 0)
            exec_echo(av);
        else if (ft_strncmp(av[1], "pwd", 3) == 0)
            exec_pwd(av);
        else if (ft_strncmp(av[1], "cd", 2) == 0)
            path = exec_cd(av);
        /* else if(ft_strncmp(av[1], "export", 6) == 0)
            exec_export(av, envp);
        else if (ft_strncmp(av[1], "unset", 5) == 0)
            exec_unset(av);
        else if (ft_strncmp(av[1], "env", 3) == 0)
            exec_env(av); */
    }
}

int main(int ac, char **av)
{
    char *path;

    path = 0;
    if (ac > 1)
    {
        if (ft_strncmp(av[1], "exit", 4) == 0)
        {
            if (path)
                free(path);
            clean_all();
            exit(0);
        }
        else 
            parse_built_in(av, path);
    }
    else 
        error_args(0);
    if (path)
        free(path);
    return (0);
}
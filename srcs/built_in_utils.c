#include "../includes/minishell.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str && str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < (n - 1) && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	j = (ft_strlen(s1) + ft_strlen(s2));
	k = 0;
	str = malloc(sizeof(char) * (j + 1));
	if (!(str))
		return (0);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[k])
		str[i++] = s2[k++];
	str[i] = '\0';
	free(s1);
	return (str);
}

void    error_args(int i)
{
    if (i == 0)
        ft_putstr("Error:\nNot enough args\n");
    else 
        ft_putstr("Error:\nToo many args\n");
}

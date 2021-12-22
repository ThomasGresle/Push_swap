#include "../includes/push_swap.h"

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

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	pick_max(int i, int j)
{
	if (i > j)
		return (i);
	else
		return (j);
}


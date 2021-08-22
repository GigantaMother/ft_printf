#include "ft_printf.h"

int	ft_print_symbol(char c, int count)
{
	int	size;

	size = 0;
	while (count > 0)
	{
		ft_parametr_normal(c, &size);
		count--;
	}
	return (size);
}

int	ft_putstr(char *s, int len)
{
	int	size;

	size = 0;
	if (s)
	{
		while (s[size] && size < len)
		{
			ft_putchar(s[size]);
			size++;
		}
	}
	return (size);
}

int	ft_max(int one, int two)
{
	if (one > two)
		return (one);
	else
		return (two);
}

int	ft_min(int one, int two)
{
	if (one < two)
		return (one);
	else
		return (two);
}

void	ft_spec_init(t_specifier *spec)
{
	spec->empty = -1;
	spec->minus = -1;
	spec->zero = -1;
	spec->accur = -1;
}

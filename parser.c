#include "ft_printf.h"

int	ft_parcer_flag(const char *str, int *i, t_specifier *spec, va_list factor)
{
	while (!ft_parcer_type(str[*i]) && str[*i])
	{
		if ((str[*i] >= '1' && str[*i] <= '9') || str[*i] == '*')
		{
			spec->empty = ft_parcer_count(str, i, spec->empty, factor);
			spec->empty = ft_parcer_minus_1(spec->empty);
		}
		else if (str[*i] == '0')
		{
			spec->zero = ft_parcer_count(str, i, spec->zero, factor);
			spec->zero = ft_parcer_minus_1(spec->zero);
		}
		else if (str[*i] == '-')
		{
			spec->minus = ft_parcer_count(str, i, spec->minus, factor);
			spec->minus = ft_parcer_minus_1(spec->minus);
		}
		else if (str[*i] == '.')
			spec->accur = ft_parcer_count(str, i, spec->accur, factor);
		else
			*i = *i + 1;
	}
	return (ft_parcer_check(spec));
}

int	ft_parcer_count(const char *str, int *i, int flag, va_list factor)
{
	if (str[*i] == '0' || str[*i] == '.' || str[*i] == '-')
		*i = *i + 1;
	if (str[*i] == '*')
	{
		flag = va_arg(factor, int);
		*i = *i + 1;
	}
	else
	{
		flag = 0;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			flag = flag * 10 + (str[*i] - 48);
			*i = *i + 1;
		}
	}
	return (flag);
}

int	ft_parcer_type(char type)
{
	if (type == '%' || type == 'c' || type == 's'
		|| type == 'd' || type == 'i' || type == 'u'
		|| type == 'x' || type == 'X' || type == 'p')
		return (1);
	else
		return (0);
}

int	ft_parcer_check(t_specifier *spec)
{
	if (spec->empty < -1)
		spec->minus = -spec->empty;
	if (spec->minus < -1)
		spec->minus = -spec->minus;
	if (spec->accur < -1)
		spec->accur = -1;
	if (spec->zero < -1)
		spec->minus = -spec->zero;
	if ((spec->empty >= 0 && spec->minus >= 0)
		|| (spec->empty >= 0 && spec->zero >= 0)
		|| (spec->minus > 0 && spec->zero > 0))
		return (0);
	else
		return (1);
}

int	ft_parcer_minus_1(int flag)
{
	if (flag == -1)
		return (1);
	else
		return (flag);
}

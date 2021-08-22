#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		size;
	va_list	factor;

	va_start(factor, str);
	size = ft_processing(str, factor);
	va_end(factor);
	if (size == -1)
		size = 0;
	return (size);
}

int	ft_processing(const char *str, va_list factor)
{
	int	len;
	int	size;
	int	i;
	int	vrem;

	len = ft_strlen(str);
	size = 0;
	i = 0;
	while (i < len)
	{
		if (str[i] == '%')
		{
			i++;
			vrem = ft_parser(str, factor, &i);
			if (vrem == -1)
				return (-1);
			else
				size += vrem;
		}
		else
			size += ft_parametr_normal(str[i], &i);
	}
	return (size);
}

int	ft_parser(const char *str, va_list factor, int *i)
{
	int			size;
	t_specifier	spec;

	size = -1;
	ft_spec_init(&spec);
	if (ft_parcer_flag(str, i, &spec, factor) == 0)
		return (-1);
	if (str[*i] == '%')
		size = ft_parameter_c(factor, spec, 0);
	else if (str[*i] == 'c')
		size = ft_parameter_c(factor, spec, 1);
	else if (str[*i] == 's')
		size = ft_parameter_s(va_arg(factor, char *), spec);
	else if (str[*i] == 'd' || str[*i] == 'i')
		size = ft_parameter_num(va_arg(factor, int), spec, str[*i]);
	else if (str[*i] == 'u' || str[*i] == 'x' || str[*i] == 'X')
		size = ft_parameter_num(va_arg(factor, unsigned int), spec, str[*i]);
	else if (str[*i] == 'p')
		size = ft_parameter_num(va_arg(factor, long int), spec, str[*i]);
	if (ft_parcer_type(str[*i]) == 1)
		*i = *i + 1;
	return (size);
}

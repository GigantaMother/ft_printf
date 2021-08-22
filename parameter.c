#include "ft_printf.h"

int	ft_parametr_normal(char c, int *i)
{
	*i = *i + 1;
	ft_putchar(c);
	return (1);
}

int	ft_parameter_c(va_list factor, t_specifier spec, int sign)
{
	int	size;

	size = 0;
	if (sign == 0)
		size += ft_print_symbol('0', spec.zero - 1);
	else if (spec.accur > 0 || spec.zero >=0)
		return (-1);
	size += ft_print_symbol(' ', spec.empty - 1);
	if (sign == 0)
		ft_parametr_normal('%', &size);
	else
		ft_parametr_normal(va_arg(factor, int), &size);
	size += ft_print_symbol(' ', spec.minus - 1);
	return (size);
}

int	ft_parameter_s(char *str, t_specifier spec)
{
	int		len;
	int		size;

	size = 0;
	len = ft_strlen(str);
	if (spec.zero >= 0)
		return (-1);
	if (spec.accur == -1)
		spec.accur = len;
	size += ft_print_symbol(' ', spec.empty - ft_min(spec.accur, len));
	if (str == NULL)
		size += ft_putstr("(null)", spec.accur);
	else
		size += ft_putstr(str, spec.accur);
	size += ft_print_symbol(' ', spec.minus - ft_min(spec.accur, len));
	return (size);
}

int	ft_parameter_num(long num, t_specifier spec, char type)
{
	int	num_len;
	int	size;

	num_len = ft_num_len(num, type);
	size = num_len;
	if (spec.accur == 0 && num == 0)
	{
		size = 0;
		size = size + ft_print_symbol(' ', spec.empty);
		size = size + ft_print_symbol(' ', spec.zero);
		size = size + ft_print_symbol(' ', spec.minus);
	}
	else if ((spec.empty >= 0 || spec.minus >= 0) && spec.accur >= 0)
		size += ft_comb_1(num, spec, type, num_len);
	else if (spec.zero >= 0 && spec.accur >= 0)
		size += ft_comb_2(num, spec, type, num_len);
	else
		size += ft_comb_3(num, spec, type, num_len);
	return (size);
}

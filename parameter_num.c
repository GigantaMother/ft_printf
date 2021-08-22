#include "ft_printf.h"

int	ft_num_len(long long int num, char type)
{
	int	num_len;

	if (type == 'u' || type == 'd' || type == 'i')
		num_len = ft_length_base(num, 10);
	else
		num_len = ft_length_base(num, 16);
	if (type == 'p')
		num_len = num_len + 2;
	return (num_len);
}

void	ft_num_print(long long int num, char type)
{
	if (type == 'u' || type == 'd' || type == 'i')
		ft_putnbr_base(num, 10, "0123456789");
	else if (type == 'x')
		ft_putnbr_base(num, 16, "0123456789abcdef");
	else if (type == 'X')
		ft_putnbr_base(num, 16, "0123456789ABCDEF");
	else
	{
		ft_putstr("0x", 2);
		ft_putnbr_base(num, 16, "0123456789abcdef");
	}
}

int	ft_comb_1(long num, t_specifier spec, char type, int num_len)
{
	int	size;

	size = 0;
	if (num < 0 && (spec.accur >= num_len))
		spec.empty--;
	size += ft_print_symbol(' ', (spec.empty - ft_max(spec.accur, num_len)));
	if (num < 0)
	{
		num = -num;
		ft_putchar('-');
		num_len--;
		spec.minus--;
	}
	size += ft_print_symbol('0', (spec.accur - num_len));
	size += ft_print_symbol('0', (spec.zero - num_len));
	ft_num_print(num, type);
	size += ft_print_symbol(' ', (spec.minus - ft_max(spec.accur, num_len)));
	return (size);
}

int	ft_comb_2(long num, t_specifier spec, char type, int num_len)
{
	int	size;

	size = 0;
	if (num < 0)
		spec.accur++;
	size = size + ft_print_symbol(' ', spec.zero - ft_max(spec.accur, num_len));
	if (num < 0)
	{
		num = -num;
		ft_putchar('-');
	}
	size = size + ft_print_symbol('0', spec.accur - num_len);
	ft_num_print(num, type);
	return (size);
}

int	ft_comb_3(long num, t_specifier spec, char type, int num_len)
{
	int	size;

	size = 0;
	size = size + ft_print_symbol(' ', (spec.empty - num_len));
	if (num < 0)
	{
		num = -num;
		ft_putchar('-');
		if (spec.accur >= 0)
			num_len--;
	}
	size = size + ft_print_symbol('0', (spec.accur - num_len));
	size = size + ft_print_symbol('0', (spec.zero - num_len));
	ft_num_print(num, type);
	size = size + ft_print_symbol(' ', (spec.minus - num_len));
	return (size);
}

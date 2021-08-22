#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(const char *s)
{
	int	size;

	if (s == NULL)
		return (6);
	size = 0;
	while (*s)
	{
		size++;
		s++;
	}
	return (size);
}

void	ft_putnbr_base(long n, int base, char *alp)
{
	if (n == 0)
		ft_putchar('0');
	else
		ft_putnbr_base_rek(n, base, alp);
}

void	ft_putnbr_base_rek(long n, int base, char *alp)
{
	if (n == 0)
		return ;
	ft_putnbr_base_rek(n / base, base, alp);
	ft_putchar(alp[n % base]);
}

int	ft_length_base(long n, int base)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 0)
	{
		n /= base;
		len++;
		if (n == 0)
			break ;
	}
	return (len);
}

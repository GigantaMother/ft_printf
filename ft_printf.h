#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_specifier
{
	int	empty;
	int	minus;
	int	zero;
	int	accur;
}				t_specifier;

int		ft_printf(const char *str, ...);
int		ft_processing(const char *str, va_list factor);
int		ft_parser(const char *str, va_list factor, int *i);

int		ft_parcer_flag(const char *str, int *i, t_specifier *spec, \
va_list factor);
int		ft_parcer_count(const char *str, int *i, int flag, va_list factor);
int		ft_parcer_type(char type);
int		ft_parcer_check(t_specifier *spec);
int		ft_parcer_minus_1(int flag);

int		ft_parametr_normal(char c, int *i);
int		ft_parameter_c(va_list factor, t_specifier spec, int sign);
int		ft_parameter_s(char *str, t_specifier spec);
int		ft_parameter_num(long num, t_specifier spec, char type);

int		ft_num_len(long long int num, char type);
void	ft_num_print(long long int num, char type);
int		ft_comb_1(long num, t_specifier spec, char type, int num_len);
int		ft_comb_2(long num, t_specifier spec, char type, int num_len);
int		ft_comb_3(long num, t_specifier spec, char type, int num_len);

int		ft_print_symbol(char c, int count);
int		ft_putstr(char *s, int len);
int		ft_max(int one, int two);
int		ft_min(int one, int two);
void	ft_spec_init(t_specifier *spec);

void	ft_putchar(char c);
int		ft_strlen(const char *s);
void	ft_putnbr_base(long n, int base, char *alp);
void	ft_putnbr_base_rek(long n, int base, char *alp);
int		ft_length_base(long n, int base);

#endif
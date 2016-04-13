/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 10:07:41 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/06 10:19:32 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>
# include <limits.h>

typedef struct		s_data
{
	wchar_t			c_spe;
	wchar_t			*s_spe;
	int				c;
	const char		*s;
}					t_data;

void				ft_put(char *s);
void				ft_error(int flag);
void				ft_opt_color(char *str, int *opt);
void				ft_clear_all(int *tab, char *flag, t_data *s);
int					ft_higher(int a, int b);
int					ft_printf(char *str, ...);
int					ft_wstrlen(wchar_t *str, int max);
int					get_max_char(t_data s, int *tab, char *flag);
void				ft_get_code(int base, long long int arg, char *flag);
void				ft_get_first_char(char **s, char *flag);
int					ft_power(int n, int puiss);
int					ft_strcount(const char *s, char b);
int					ft_strlen_char(const char *s, char b);
void				ft_putnb_base(long long int nb, char *base);
void				ft_putnb_base2(unsigned long long int nb, char *base);
int					ft_nb_len_base(long long int n, int base);
int					ft_nb_len_base2(unsigned long long int n, int base);
void				ft_get_opt(char **s, char *flag, int *tab);
void				final_check(char *flag, int *tab);
void				ft_get_last_char(char **s, char *flag);
long long int		get_int_flagged(va_list va, char c, char d);
void				get_arg(va_list va, char *flag, int *tab, t_data s);
long long int		get_arg_nb(va_list va, char c, char *flag);
long long int		get_uint_flagged(va_list va, char c, char d);
void				ft_putwchar(wchar_t c);
void				ft_putwstr(wchar_t *str, int n);
void				do_wrd(char *flag, int *tab, t_data s);
void				do_nb(char *flag, int *tab, long long int arg);
void				print_beg(char *f, int *tab, int m, long long int a);
int					ft_atoi(char *str);
void				ft_print_n_char(char c, int n);
int					get_total_char(long long int arg, char *flag, int *tab);
int					ft_get_char(char *s, char c);
void				ft_putchar(char c);
void				ft_putstr(char const *s, int n);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strdup(const char *str);
int					ft_strlen(const char *c);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);

#endif

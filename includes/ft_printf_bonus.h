/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:48:34 by mpalkov           #+#    #+#             */
/*   Updated: 2022/09/09 15:06:28 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

# define VALIDFORMAT "cspdiuxX% +#"
# define HEXFLAGS "#"
# define DECFLAGS " +"

typedef struct s_vars
{
	char	*format;
	int		pos_s;
	int		printcount;
	char	*strn;
	va_list	args;
	int		lastreturn;
	char	caseflag;
}				t_vars;

int			ft_printf(const char *str, ...);

int			ft_print_char(t_vars *vars, char c);
int			ft_print_str(t_vars *vars, char *str);
int			ft_pf_perc(t_vars *vars);
int			ft_print_unsint(t_vars *vars, long nbr);
int			ft_print_hex_case(t_vars *vars, unsigned long long nbr);

int			ft_pf_c(t_vars *vars);
int			ft_pf_s(t_vars *vars);

int			ft_pf_d(t_vars *vars);
int			ft_pf_u(t_vars *vars);

int			ft_pf_x(t_vars *vars);
int			ft_pf_p(t_vars *vars);

int			ft_flagcheck(t_vars *vars);

#endif

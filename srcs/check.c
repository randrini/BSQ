/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrini <randrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 16:51:02 by randrini          #+#    #+#             */
/*   Updated: 2016/02/06 17:05:18 by randrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_error(void)
{
	ft_putstr("map error\n");
	exit(1);
}

int		ft_strlen_mod(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

void	ft_check_grid(char *str)
{
	int i;
	int	j;
	int k;

	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	i += 1;
	while (str[++i] != '\n' && str[i] != '\0')
		j++;
	i += 1;
	k = i;
	while (str[i] != '\0')
	{
		while (str[i] != '\n' && str[i] != '\0')
			++i;
		if ((i - 1 - k) != j)
			ft_error();
		else
		{
			i++;
			k = i;
		}
	}
}

void	ft_check_char(char *buf)
{
	int		i;
	t_param *tmp_param;

	i = skip_first_line(buf);
	tmp_param = ft_get_parameters(buf);
	while (buf[i] != '\0')
	{
		if (buf[i] == tmp_param->empty ||
				buf[i] == tmp_param->obst || buf[i] == '\n')
			i++;
		else
			ft_error();
	}
}

int		ft_check_full_o(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	i++;
	while (str[i] != '\0')
	{
		if (str[i] == 'o' || str[i] == '\n')
			i++;
		else
			return (0);
	}
	ft_error();
	return (1);
}

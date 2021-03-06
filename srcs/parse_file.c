/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrini <randrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:37:00 by randrini          #+#    #+#             */
/*   Updated: 2016/02/06 19:10:31 by randrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*first_line(char *buf)
{
	char	*first_line;
	int		i;

	i = 0;
	if (buf[0] == '\0')
		ft_error();
	while (buf[i] != '\n')
		i++;
	first_line = (char*)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (buf[i] != '\n')
	{
		first_line[i] = buf[i];
		i++;
	}
	first_line[i] = '\0';
	return (first_line);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_intlen(int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		++i;
	}
	return (i);
}

void	ft_check_file(char *buf)
{
	int		i;
	char	*str;
	t_param *tmp_param;

	i = 0;
	str = first_line(buf);
	tmp_param = ft_get_parameters(buf);
	if (str[0] >= 48 && str[0] <= 57)
	{
		str[ft_strlen_mod(buf) - 3] = '\0';
		if (ft_atoi(str) != size_col(buf))
			ft_error();
		i = ft_intlen(ft_atoi(str));
		str = first_line(buf);
		if (str[i] == tmp_param->empty)
			i++;
		if (str[i] == tmp_param->obst)
			i++;
		if (str[i] == tmp_param->full)
			i++;
		else
			ft_error();
	}
	else
		ft_error();
}

char	*parse_file(char *file)
{
	int			fd;
	int			ret;
	static char	buf[BUFFER_SIZE];

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error();
	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	close(fd);
	ft_check_file(buf);
	ft_check_char(buf);
	ft_check_full_o(buf);
	ft_check_grid(buf);
	return (buf);
}

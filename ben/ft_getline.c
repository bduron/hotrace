/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 17:30:38 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/27 20:05:13 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static int		from_buff(char ***line, char **str, ssize_t ret)
{
	char	*tmp;

	if (ft_strchr(*str, '\n'))
	{
		**line = ft_strsub(*str, 0, (ft_strlen(*str) -
					ft_strlen(ft_strchr(*str, '\n'))));
		tmp = ft_strdup(ft_strchr(*str, '\n') + 1);
		ft_strdel(str);
		if (ft_strlen(tmp) > 0)
			*str = ft_strdup(tmp);
		ft_strdel(&tmp);
		return (1);
	}
	else if (ret < BUFF_SIZE)
	{
		**line = ft_strsub(*str, 0, ft_strlen(*str));
		ft_strdel(str);
		return (1);
	}
	return (0);
}

static int		from_remainder(char ***line, char **str)
{
	char	*tmp;

	if (*str)
	{
		if (ft_strchr(*str, '\n'))
		{
			**line = ft_strsub(*str, 0, (ft_strlen(*str) -
						ft_strlen(ft_strchr(*str, '\n'))));
			tmp = ft_strdup(ft_strchr(*str, '\n') + 1);
			ft_strdel(str);
			if (ft_strlen(tmp) > 0)
				*str = ft_strdup(tmp);
			ft_strdel(&tmp);
			return (1);
		}
	}
	return (0);
}

static char		*put_in_str(char **str, char *buff, ssize_t ret)
{
	char	*tmp;
	char	*tmp_buff;

	tmp_buff = ft_strsub(buff, 0, ret);
	if (*str)
	{
		tmp = ft_strjoin(*str, tmp_buff);
		ft_strdel(str);
	}
	else
		tmp = ft_strdup(tmp_buff);
	ft_strdel(&tmp_buff);
	return (tmp);
}

int				ft_getline(const int fd, char **line)
{
	static char	*str;
	ssize_t		ret;
	char		buff[BUFF_SIZE + 1];

	ret = 0;
	if (from_remainder(&line, &str) == 1)
		return (1);
	if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
		return (-1);
	if (ret == 0 && !str)
		return (0);
	str = put_in_str(&str, buff, ret);
	if (from_buff(&line, &str, ret) == 0)
		ft_getline(fd, line);
	return (1);
}

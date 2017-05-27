/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:35:32 by cpoulet           #+#    #+#             */
/*   Updated: 2017/05/27 18:43:03 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_addressing.h"

size_t	ft_strlen(const char *s)
{
	const char	*init;

	init = s;
	while (s && *s)
		++s;
	return (s - init);
}

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char*)malloc(sizeof(*str) * (size + 1));
	while (size != 0)
		str[size--] = '\0';
	str[0] = '\0';
	return (str);
}

void	ft_strdel(char **as)
{
	if (as && *as)
	{
		free(*as);
		*as = 0;
	}
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(*str) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ret = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (ret);
}

int	ft_getline_ben(const int fd, char **line)
{
	char	buff[2];
	char	*tmp;
	int		ret;

	*line = ft_strnew(0);
	while ((ret = read(fd, buff, 1)) > 0)
	{
		buff[1] = '\0';
		if (*buff == '\n')
			break ;
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		ft_strdel(&tmp);
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 11:19:57 by cpoulet           #+#    #+#             */
/*   Updated: 2017/05/27 19:29:56 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define HASH_SIZE 1008001

typedef struct		s_bucket
{
	char			*key;
	char			*val;
	struct s_bucket	*next;
}					t_bucket;

size_t			ft_strlen(const char *s);
int				ft_getline(const int fd, char **line);
unsigned int	murmurhash(char *key, unsigned int nbytes);

#endif

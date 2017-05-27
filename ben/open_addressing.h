/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_addressing.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 16:03:52 by bduron            #+#    #+#             */
/*   Updated: 2017/05/27 20:05:12 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPEN_ADDRESSING_H
# define OPEN_ADDRESSING_H	

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define TABSIZ 7000003
# define ALPHA 94

typedef struct	s_bucket 
{
	char *key;
	char *val;
}				t_bucket;

int	ft_getline(const int fd, char **line);

#endif

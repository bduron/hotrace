/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 17:33:26 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/27 20:05:14 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "ft_string.h"

# include <unistd.h>

# define BUFF_SIZE 128

int			ft_getline(const int fd, char **line);
void		ft_putstr_fd(int fd, const char *s);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 11:11:01 by cpoulet           #+#    #+#             */
/*   Updated: 2017/05/27 11:19:10 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	main(void)
{
	char *line;

	while (ft_getline(0, &line))
	{
		printf("%s\n", line);
	}
	return (0);
}
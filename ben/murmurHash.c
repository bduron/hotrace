/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   murmurhash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 13:48:43 by cpoulet           #+#    #+#             */
/*   Updated: 2017/05/27 14:55:49 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace"

unsigned int	murmurhash(unsigned char *key, unsigned int nbytes)
{
	const unsigned int	*blocks;
	const unsigned char	*tail;
	unsigned int		h;
	unsigned int		k;
	int					nblocks;
	int					i;

	nblocks	= nbytes / 4; // a tester nbytes << 2
	blocks = (const unsigned int *)(key);
	tail = (const unsigned char *)(key + (nblocks * 4)); //nblocks >> 2
	h = 0;
	i = 0;
	while (i < nblocks)
	{
		k = blocks[i];
		k *= 0xcc9e2d51;
		k = (k << 15) | (k >> (32 - 15));
		k *= 0x1b873593;
		h ^= k;
		h = (h << 13) | (h >> (32 - 13));
		h = h * 5 + 0xe6546b64;
		i++;
	}
	k = 0;
	if ((nbytes & 3) == 3)
		k ^= tail[2] << 16;
	else if ((nbytes & 3) == 2)
		k ^= tail[1] << 8;
	else if ((nbytes & 3) == 1)
	{
		k ^= tail[0];
		k *= 0xcc9e2d51;
		k = (k << 15) | (k >> (32 - 15));
		k *= 0x1b873593;
		h ^= k;
	}
	h ^= nbytes;
	h ^= h >> 16;
	h *= 0x85ebca6b;
	h ^= h >> 13;
	h *= 0xc2b2ae35;
	h ^= h >> 16;
	return (h);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 11:38:13 by bduron            #+#    #+#             */
/*   Updated: 2017/05/27 18:52:39 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_addressing.h"

long	ft_pow(int n, int pow)
{
	long res;

	res = 1;
	while (pow--)
		res *= n;
	return (res);
}

int            ft_hash(int hashtable, char *key)
{
	int        hashvalue;

	hashvalue = 1587;
	while (*key)
	{
		hashvalue <<= 8;
		hashvalue += *key;
		key++;
	}
	return (hashvalue % hashtable);
}


unsigned long	hash_skiena(char *s, int tab_size)
{
	unsigned long hash_skiena;
	size_t len; 
	int i; 

	//len = strlen(s);
	len = 256;
	hash_skiena = 0;
	i = 0;
	while (i < len)
	{
		hash_skiena += (ft_pow(ALPHA, len - (i + 1)) * s[i]);
		i++;
	}
	return (hash_skiena % tab_size);
}


int main(int argc, char **argv)
{
	long res; 


	//printf("hash_skiena(\"%s\") = %ld\n", argv[1], hash_skiena(argv[1], atoi(argv[2])));	

//	for (int i = 0; i < 10000; i++)
//		hash_skiena(argv[1], 111);	
//	printf("OK\n");

	for (int i = 0; i < 5000000; i++)
		ft_hash(111, argv[1]);	
	printf("OK\n");

	/* Pow test */

	//	res = ft_pow(atoi(argv[1]), atoi(argv[2]));
	//	printf("%s ^ %s = %ld", argv[1], argv[2], res);	

	return (0);
}

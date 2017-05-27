/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 11:38:13 by bduron            #+#    #+#             */
/*   Updated: 2017/05/27 14:23:30 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALPHA 94

long	ft_pow(int n, int pow)
{
	long res;

	res = 1;
	while (pow--)
		res *= n;
	return (res);
}


unsigned long	hash_skiena(char *s, int size)
{
	unsigned long hash_skiena;
	size_t len; 
	int i; 
		
	len = strlen(s);
	hash_skiena = 0;
	i = 0;
	while (i < len)
	{
		hash_skiena += (ft_pow(ALPHA, len - (i + 1)) * s[i]);
		i++;
	}
	return (hash_skiena % size);
}


int main(int argc, char **argv)
{
	long res; 

	printf("hash_skiena(\"%s\") = %ld\n", argv[1], hash_skiena(argv[1], atoi(argv[2])));	
	
	/* Pow test */

//	res = ft_pow(atoi(argv[1]), atoi(argv[2]));
//	printf("%s ^ %s = %ld", argv[1], argv[2], res);	

	return (0);
}

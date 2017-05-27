/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_addressing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 16:02:19 by bduron            #+#    #+#             */
/*   Updated: 2017/05/27 20:05:15 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_addressing.h"

int hash(int hashtable, char *key)
{
	int        hashvalue;

	hashvalue = 1583;
	while (*key)
	{
		hashvalue <<= 8;
		hashvalue += *key;
		key++;
	}
	return (hashvalue % hashtable);
}

void query_val(t_bucket *hashtab)
{
	char *line;
	int index;

	while (ft_getline(0, &line))
	{
		index = hash(TABSIZ, line);

		while (hashtab[index].key != NULL && strcmp(line, hashtab[index].key) != 0)
			index++;

		if (hashtab[index].key != NULL)
	//		printf("%s: %s\n", line, hashtab[index].val);//	
			printf("%s\n", hashtab[index].val);	
		else 
			printf("%s: Not found.\n", line);	
	}
}

void insert_keyval(t_bucket *hashtab, char *key, char *val)
{
	int index;

	index = hash(TABSIZ, key); // passer un pointeur sur fonction

	while (hashtab[index % TABSIZ].key != NULL) // desactiver ca et faire la diff pour avoir ncolisions
		index++;

	hashtab[index].key = key;
	hashtab[index].val = val;
}


void create_hashtab(t_bucket *hashtab)
{
	char *key;
	char *val;	

	while (ft_getline(0, &key))
	{	
		if (*key == '\0')
			break;
		ft_getline(0, &val);

		insert_keyval(hashtab, key, val);
	}
}


int main(int argc, char **argv)
{
	static t_bucket		hashtab[TABSIZ];

	create_hashtab(hashtab);
	query_val(hashtab);

	for (int i = 0; i < TABSIZ; i++)
	{
		if (hashtab[i].key == NULL)
			continue;
		  // printf("hashtab[%d] = NULL\n", i);	
		else 
		   printf("hashtab[\"%s\"] = %s		[%d]\n", hashtab[i].key, hashtab[i].val, i);	

	}	

	

	return (0);
}


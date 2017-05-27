/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 11:11:01 by cpoulet           #+#    #+#             */
/*   Updated: 2017/05/27 20:04:38 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*ret;

	ret = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (ret);
}

char	*ft_strdup(const char *src)
{
	char	*str;

	str = (char*)malloc(sizeof(*str) * (ft_strlen(src) + 1));
	ft_strcpy(str, src);
	return (str);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	get_bucket(char *key, t_bucket *b)
{
	while (b->key && ft_strcmp(key, b->key))
	{
//		printf("LOOKING = %s\nkey = %s\tval = %s\tnext = %x\n", key, b->key, b->val, b->next);
		if (b->next)
			b = b->next;
		else
			break;
	}
	if (b && b->key && !(ft_strcmp(b->key, key)))
		printf("%s\n", b->val);
	else
		printf("%s: Not found.\n", key);
	return (0);
}

int	insert_bucket(char *key, t_bucket *b)
{
	t_bucket 	*new;
	int			ret;

	while (b)
	{
//		printf("LOOKING = %s\nkey = %s\tval = %s\tnext = %x\n", key, b->key, b->val, b->next);
		if (!(ft_strcmp(key, b->key)))
		{
			ret = ft_getline(0, &b->val);
			return (ret);
		}
		if (b->next == NULL)
			break;
		b = b->next;
	}
	new = (t_bucket*)malloc(sizeof(t_bucket));
	b->next = new;
	new->key = ft_strdup(key);
	new->next = NULL;
	return (ft_getline(0, &new->val));
}

int	main(void)
{
	int				ret;
	char			*addr;
	char 			*key;
	unsigned int	h;
	static t_bucket	hash[HASH_SIZE];

	ret = 1;
	while (ft_getline(0, &key))
	{
		if (!(ft_strcmp(key, "")))
			break;
		h = murmurhash(key, ft_strlen(key)) % HASH_SIZE;
		if (hash[h].key == NULL)
		{
			hash[h].key = ft_strdup(key);
			ft_getline(0, &hash[h].val);
//			printf("hash[\"%10s\"] = %10s\t[%d]\n", hash[h].key, hash[h].val, h);
		}
		else
			insert_bucket(key, &hash[h]);
		free(key);
	}
//	printf("_____\n");
	while (ft_getline(0, &key))
	{
		get_bucket(key, &hash[murmurhash(key, ft_strlen(key)) % HASH_SIZE]);
		free(key);
	}
	return (0);
}

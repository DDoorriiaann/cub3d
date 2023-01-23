/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:39:16 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/14 15:39:24 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static unsigned int	count_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	wrds;

	i = 0;
	wrds = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{	
		if ((s[i] == c && s[i + 1] != c) || (s[i] != c && !s[i + 1]))
			wrds++;
		i++;
	}
	if (s[0] != c && wrds == 0)
		wrds = 1;
	return (wrds);
}

static char	*get_word(char const *s, char c, unsigned int *i)
{
	unsigned int	j;
	char			*word;

	j = *i;
	while (s[j] && s[j] != c)
		j++;
	word = ft_substr(s, *i, (j - *i));
	*i = j;
	return (word);
}

static void	fill_arr(char const *s, char c, char **wrds_arr, unsigned int wrds)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s[i] && j < wrds)
	{	
		if (s[i] == c && s[i + 1])
			i++;
		if (s[i] != c)
		{	
			wrds_arr[j] = get_word(s, c, &i);
			j++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	unsigned int	wrds;
	char			**wrds_arr;

	if (!s)
		return (NULL);
	if (!s[0])
	{
		wrds_arr = malloc(sizeof(char *) * 1);
		wrds_arr[0] = NULL;
		return (wrds_arr);
	}
	wrds = count_words(s, c);
	wrds_arr = malloc(sizeof(char *) * (wrds + 1));
	if (!wrds_arr)
		return (NULL);
	fill_arr(s, c, wrds_arr, wrds);
	wrds_arr[wrds] = NULL;
	return (wrds_arr);
}

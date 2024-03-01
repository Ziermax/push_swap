/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultra_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:40:28 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/02/26 18:14:37 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	count_words(char *str, char c)
{
	int	count;
	int	is_word;

	count = 0;
	is_word = 0;
	while (*str)
	{
		if (*str != c && !is_word)
		{
			is_word = 1;
			count++;
		}
		else if (*str == c && is_word)
			is_word = 0;
		str++;
	}
	return (count);
}

char	*my_strdup_char(char *str, int *position, char c)
{
	char	*new_word;
	int		nword_len;
	int		i_nword;
	int		i;

	nword_len = 0;
	i_nword = 0;
	i = 0;
	while (str[i] == c)
		i++;
	while (str[i + nword_len] != c && str[i + nword_len])
		nword_len++;
	new_word = malloc(sizeof(char) * (nword_len + 1));
	if (!new_word)
		return (NULL);
	while (i_nword < nword_len)
		new_word[i_nword++] = str[i++];
	new_word[i_nword] = '\0';
	*position += i;
	return (new_word);
}

char	**split_arg(char *str, int *arg_count, char c)
{
	char	**split;
	int		words;
	int		i;
	int		i_split;

	if (!str)
		return (NULL);
	i = 0;
	i_split = 0;
	words = count_words(str, c);
	split = malloc(sizeof(char *) * words);
	if (!split)
		return (NULL);
	while (i_split < words)
	{
		split[i_split] = my_strdup_char(str + i, &i, c);
		if (!split[i_split])
			return (free_split(split, i_split), NULL);
		i_split++;
	}
	*arg_count = words;
	return (split);
}

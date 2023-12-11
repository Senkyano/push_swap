/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:20:48 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/05 13:34:09 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	count_words(const char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		while (*str == ' ' && *str)
			str++;
		if (*str != ' ' && *str != '\0')
			i++;
		while (*str != ' ' && *str)
			str++;
	}
	return (i);
}

char	*words(const char *str)
{
	int	i;
	char	*word;

	i = 0;
	while (*str == ' ' && *str)
		str++;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	word = malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (*str != ' ' && *str != '\0')
	{
		word[i++] = *str;
		str++;
	}
	word[i] = '\0';
	return (word);
}

void	freesplit(char **sent)
{
	int	i;

	i = 0;
	while (sent[i])
		free(sent[i++]);
	free(sent);
}

char	**ft_split(const char *str)
{
	char	**sent;
	int		i;

	sent = malloc((count_words(str) + 1) * sizeof(char *));
	if (!sent)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str == ' ' && *str)
			str++;
		if (*str != ' ' && *str)
			sent[i] = words(str);
		if (sent[i++] == NULL)
		{
			freesplit(sent);
			return (NULL);
		}
		while (*str != ' ' && *str)
			str++;
	}
	sent[i] = NULL;
	return (sent);
}

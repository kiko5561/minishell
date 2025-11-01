/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:41:12 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/01 23:02:56 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizing.h"

static char	*get_word(char *str);

// Take string and split it to diff token
t_token	**tokenizer(char *str)
{
	// int		i;
	char	*temp;
	char	**cmd;
	
	if (!str)
		return (NULL);
	cmd = ft_split(str, ' ');
	temp = get_word(str);
	printf("%s\n", temp);
	return (NULL);
}

char	*get_word(char *str)
{
	static int	start;
	int			j;
	int			i;
	char		*temp;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i + start] != 32)
		i++;
	temp = malloc(sizeof(char) * i);
	if (!temp)
		return (NULL);
	j = 0;
	while (str[j + start])
	{
		temp[j] = str[j + start];
		j++;
	}
	temp[j] = '\0';
	j = 0;
	start += (i + 1);
	if (str[i] == '\0')
		start = 0;
	return (temp);
}

// check for metacharacters, if metacharcter found, return true
int	check_m_char(char str)
{
	int	j;

	j = 0;
	while (j < 9)
	{
		if (str == METACHARACTERS[j])
			return (1);
		j++;
	}
	return (0);
}

void	add_token(t_token **token, char *str)
{
	t_token	*temp;

	temp = new_node(str);
	tokadd_back(token, temp);
}

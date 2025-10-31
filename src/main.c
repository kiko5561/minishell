/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:50:10 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/31 18:05:06 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main()
{
	char	*line;

	while (1)
	{
		line = readline("Line here: ");
		printf("line is: %s\n", line);
		printf("number of token is: %d\n", count_key(line));
	}
	return (0);
}
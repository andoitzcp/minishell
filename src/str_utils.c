/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:14:26 by iubieta-          #+#    #+#             */
/*   Updated: 2025/03/08 12:53:01 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	indexof(char *str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	is_special_char(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '$');
}

int	count_quoted_chars(char *input)
{
	int		i;
	char	c;

	i = 0;
	if (input[i] == '"' || input[i] == '\'')
	{
		c = input[i++];
		while (input[i] && input[i] != c)
			i++;
	}
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*cs1;
	unsigned char	*cs2;

	cs1 = (unsigned char *) s1;
	cs2 = (unsigned char *) s2;
	while (*cs1 == *cs2 && *cs1 && *cs2)
	{
		cs1 ++;
		cs2 ++;
	}
	return (*cs1 - *cs2);
}

char *artostr(char **ar)
{
	char	*str;
	char	*del;

	str = ft_calloc(10, sizeof(char));
	while (ar && *ar)
	{
		del = str;
		str = ft_strjoin(str, *ar);
		free(del);
		del = str;
		str = ft_strjoin(str, " ");
		free(del);
		ar++;
	}
	del = NULL;
	return (str);
}

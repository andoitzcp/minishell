/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ar_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:13:33 by iubieta-          #+#    #+#             */
/*   Updated: 2025/01/12 19:36:45 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Removes char* at del position from a char** array
char	**arremove(char **array, size_t del)
{
	char	**new_array;
	size_t	len;
	size_t	i;
	size_t	j;

	len = arlen(array);
	if (del >= len)
		return (array);
	new_array = ft_calloc(len, sizeof(char *));
	i = 0;
	j = 0;
	while (i < len)
	{
		if (i == del)
			j = 1;
		new_array[i] = array[i + j];
		i++;
	}
	free(array);
	array = NULL;
	return (new_array);
}

// Concatenates a char* at the end of a char** array
char	**arcat(char **array, char *str)
{
	char	**new_array;
	size_t	len;
	size_t	i;

	len = arlen(array);
	new_array = ft_calloc(len + 2, sizeof(char *));
	i = 0;
	while (i < len)
	{
		new_array[i] = array[i];
		i++;
	}
	new_array[i++] = ft_strdup(str);
	new_array[i] = NULL;
	free(array);
	array = NULL;
	return (new_array);
}

// Returns the length of a char** array
size_t	arlen(char **array)
{
	size_t	i;

	i = 0;
	if (!array)
		return (i);
	while (array[i])
		i++;
	return (i);
}

// Prints a char** array
void	arprint(char **array)
{
	size_t	i;

	if (!array)
	{
		printf("%p\n", array);
		return ;
	}
	i = 0;
	printf("ptr: %p\n{ ", array);
	while (array[i])
		printf("\"%s\" ", array[i++]);
	printf("}\n");
}

// Frees a char** array
void	arfree(char **array)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
	return ;
}

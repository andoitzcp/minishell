/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:59:03 by iubieta-          #+#    #+#             */
/*   Updated: 2025/05/06 20:47:21 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

t_var	*initenv()
{
	extern char	**environ;
	t_var	*env;
	t_var	var;
	size_t	i;
	
	env = (t_var *)malloc(sizeof(t_var));
	i = 0;
	while (environ && environ[i])
	{
		var = strtovar(environ[i], 1);
		env = add_var(env, var);
		i++;
	}
	// printenv(env);
	return (env);
}

void	printenv(t_var	*env)
{
	t_var	*cur;
	int	i;

	cur = env;
	i = 1;
	while (cur)
	{
		printf("Var %i: key = %s, value = %s, exported = %i\n", i, cur->key, cur->value, cur->exported);
		cur = cur->next;
		i++;
	}
}


char	**envtoarray(t_var *env)
{
	char **ar;
	t_var	*cur;
	size_t	len;
	size_t	i;

	len = 0;
	cur = env;
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	ar = (char **)malloc(sizeof(char *) * (len + 1));
	i = 0;
	cur = env;
	while (cur)
	{
		ar[i] = vartostr(*cur);
		cur = cur->next;
		i++;
	}
	return (ar);
}

char	*expand_var(t_var *env, char *key)
{
	t_var	*var;
	
	var = varfind(env, key);
	if (var)
		return (var->value);
	return (NULL);
}


int	key_cmp(char *k1, char *k2)
{
	size_t	l1;
	size_t	l2;

	l1 = ft_strlen(k1);
	l2 = ft_strlen(k2);
	if (l1 == l2 && ft_strncmp(k1, k2, l1) == 0)
		return (0);
	return (1);
}

t_var	*varfind(t_var	*env, char *key)
{
	t_var	*cur;

	if (!env || !key)
		return (NULL);
	cur = env;
	while (cur)
	{
		if (key_cmp(cur->key, key) == 0)
			return(cur);
		cur = cur->next;
	}
	return (NULL);
}


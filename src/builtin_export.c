/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:44:15 by iubieta-          #+#    #+#             */
/*   Updated: 2025/03/23 19:46:25 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

// Replace a char** element with a new char*
void	armod(char	**ar_pos, char	*str)
{
	char	*del;

	del = *ar_pos;
	*ar_pos = ft_strdup(str);
	free(del);
	del = NULL;
}

int	ft_export(char ***env_ptr, char **args)
{
	char	**env;
	char	*var;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!args || !env_ptr)
	{
		printf("export: not enough arguments\n");
		return (1);
	}
	i = 1;
	env = *env_ptr;
	while (args[i])
	{
		len = ft_strlen(args[i]);
		//REVISAR: ñapa?? revisar leaks de memoria
		if (len == (indexof(args[i], '=') + 1))
		{
			var = ft_substr(args[i], 0, indexof(args[i], '=' + 1));
			i++;
			args[i] = ft_strjoin(var, args[i]);
		}
		var = ft_substr(args[i], 0, indexof(args[i], '='));
		j = envfind(env, var);
		if (env[j])
			armod(&env[j], args[i]);
		else
			env = arcat(env, args[i]);
		i++;
	}
	*env_ptr = env;
	return (0);
}

// TEST
// int	main()
// {
// 	char	**env;
// 	char	**args;
//
// 	printf("\n--Test 1--\n");
// 	args = ft_calloc(10, sizeof(char *));
// 	args[0] = ft_strdup("Var1=Value1");
// 	args[1] = NULL;
// 	arprint(NULL);
// 	ft_export(NULL, args);
// 	arprint(NULL);
// 	arfree(args);
//
// 	printf("\n--Test 2--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = NULL;
// 	arprint(env);
// 	ft_export(&env, NULL);
// 	arprint(env);
// 	arfree(env);
//
// 	printf("\n--Test 3--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	arprint(env);
// 	args = ft_calloc(10, sizeof(char *));
// 	args[0] = ft_strdup("Var1=Value1");
// 	args[1] = NULL;
// 	ft_export(&env, args);
// 	arprint(env);
// 	arfree(env);
// 	arfree(args);
//
// 	printf("\n--Test 4--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = NULL;
// 	arprint(env);
// 	args = ft_calloc(10, sizeof(char *));
// 	args[0] = ft_strdup("Var1=Value2");
// 	args[1] = NULL;
// 	ft_export(&env, args);
// 	arprint(env);
// 	arfree(env);
// 	arfree(args);
//
// 	printf("\n--Test 5--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = ft_strdup("Var2=Value2");
// 	env[2] = ft_strdup("Var3=Value3");
// 	env[3] = ft_strdup("Var4=Value4");
// 	env[4] = NULL;
// 	arprint(env);
// 	args = ft_calloc(10, sizeof(char *));
// 	args[0] = ft_strdup("VarN=ValueN");
// 	args[1] = ft_strdup("VarN+1=ValueN+1");
// 	args[2] = ft_strdup("VarN+2=ValueN+2");
// 	args[3] = ft_strdup("VarN+3=ValueN+3");
// 	args[4] = NULL;
// 	ft_export(&env, args);
// 	arprint(env);
// 	arfree(env);
// 	arfree(args);
// 	
// 	printf("\n--Test 6--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = ft_strdup("Var2=Value2");
// 	env[2] = ft_strdup("Var3=Value3");
// 	env[3] = ft_strdup("Var4=Value4");
// 	env[4] = NULL;
// 	arprint(env);
// 	args = ft_calloc(10, sizeof(char *));
// 	args[0] = ft_strdup("Var=ValueN");
// 	args[1] = ft_strdup("Var1=ValueN+1");
// 	args[2] = ft_strdup("Var2=ValueN+2");
// 	args[3] = ft_strdup("Var3=ValueN+3");
// 	args[4] = NULL;
// 	ft_export(&env, args);
// 	arprint(env);
// 	arfree(env);
// 	arfree(args);
//
// }

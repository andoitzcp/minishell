/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:44:15 by iubieta-          #+#    #+#             */
/*   Updated: 2025/03/08 17:42:37 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	ft_armod(char	**ar_pos, char	*str)
{
	char	*del;

	del = *ar_pos;
	*ar_pos = ft_strdup(str);
	free(del);
	del = NULL;
}

void	ft_export(char ***env_ptr, char **args)
{
	char	**env;
	char	*var;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!args || !env_ptr)
	{
		printf("export: not enough arguments\n");
		return ;
	}
	ft_arprint(args);
	i = 1;
	env = *env_ptr;
	while (args[i])
	{
		printf("export: args[i]=%s\n", args[i]);
		len = ft_strlen(args[i]);
		//REVISAR: ñapa?? revisar leaks de memoria
		if (len == (ft_indexof(args[i], '=') + 1))
		{
			var = ft_substr(args[i], 0, ft_indexof(args[i], '=' + 1));
			printf("export: var=%s\n", var);
			i++;
			args[i] = ft_strjoin(var, args[i]);
			printf("export: new args[i]=%s\n", args[i]);
		}
		var = ft_substr(args[i], 0, ft_indexof(args[i], '='));
		j = ft_envfind(env, var);
		if (env[j])
			ft_armod(&env[j], args[i]);
		else
			env = ft_arcat(env, args[i]);
		i++;
	}
	*env_ptr = env;
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
// 	ft_arprint(NULL);
// 	ft_export(NULL, args);
// 	ft_arprint(NULL);
// 	ft_arfree(args);
//
// 	printf("\n--Test 2--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = NULL;
// 	ft_arprint(env);
// 	ft_export(&env, NULL);
// 	ft_arprint(env);
// 	ft_arfree(env);
//
// 	printf("\n--Test 3--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	ft_arprint(env);
// 	args = ft_calloc(10, sizeof(char *));
// 	args[0] = ft_strdup("Var1=Value1");
// 	args[1] = NULL;
// 	ft_export(&env, args);
// 	ft_arprint(env);
// 	ft_arfree(env);
// 	ft_arfree(args);
//
// 	printf("\n--Test 4--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = NULL;
// 	ft_arprint(env);
// 	args = ft_calloc(10, sizeof(char *));
// 	args[0] = ft_strdup("Var1=Value2");
// 	args[1] = NULL;
// 	ft_export(&env, args);
// 	ft_arprint(env);
// 	ft_arfree(env);
// 	ft_arfree(args);
//
// 	printf("\n--Test 5--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = ft_strdup("Var2=Value2");
// 	env[2] = ft_strdup("Var3=Value3");
// 	env[3] = ft_strdup("Var4=Value4");
// 	env[4] = NULL;
// 	ft_arprint(env);
// 	args = ft_calloc(10, sizeof(char *));
// 	args[0] = ft_strdup("VarN=ValueN");
// 	args[1] = ft_strdup("VarN+1=ValueN+1");
// 	args[2] = ft_strdup("VarN+2=ValueN+2");
// 	args[3] = ft_strdup("VarN+3=ValueN+3");
// 	args[4] = NULL;
// 	ft_export(&env, args);
// 	ft_arprint(env);
// 	ft_arfree(env);
// 	ft_arfree(args);
// 	
// 	printf("\n--Test 6--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = ft_strdup("Var2=Value2");
// 	env[2] = ft_strdup("Var3=Value3");
// 	env[3] = ft_strdup("Var4=Value4");
// 	env[4] = NULL;
// 	ft_arprint(env);
// 	args = ft_calloc(10, sizeof(char *));
// 	args[0] = ft_strdup("Var=ValueN");
// 	args[1] = ft_strdup("Var1=ValueN+1");
// 	args[2] = ft_strdup("Var2=ValueN+2");
// 	args[3] = ft_strdup("Var3=ValueN+3");
// 	args[4] = NULL;
// 	ft_export(&env, args);
// 	ft_arprint(env);
// 	ft_arfree(env);
// 	ft_arfree(args);
//
// }

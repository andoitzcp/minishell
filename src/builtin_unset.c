/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:55:07 by iubieta-          #+#    #+#             */
/*   Updated: 2025/03/23 19:32:56 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset(char ***env_ptr, char **args)
{
	char	**env;
	size_t	i;
	size_t	j;

	if (!args || !env_ptr)
	{
		printf("unset: not enough arguments\n");
		return (1);
	}
	i = 1;
	env = *env_ptr;
	while (args[i])
	{
		j = envfind(env, args[i]);
		if (env[j])
			env = arremove(env, j);
		i++;
	}
	*env_ptr = env;
	return (0);
}

// TEST
// int	main()
// {
// 	char	**args;
// 	char	**env;
//
//
// 	printf("\n--Test 1--\n");
// 	args = ft_calloc(10, sizeof(char *));
// 	args[0] = ft_strdup("Var1");
// 	args[1] = NULL;
// 	arprint(NULL);
// 	unset(NULL, args);
// 	arprint(NULL);
// 	arfree(args);
//
// 	printf("\n--Test 2--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = NULL;
// 	arprint(env);
// 	unset(&env, NULL);
// 	arprint(env);
// 	arfree(env);
//
// 	printf("\n--Test 3--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = NULL;
// 	arprint(env);
// 	args = ft_calloc(10, sizeof(char *));
// 	args[0] = ft_strdup("Var1");
// 	args[1] = NULL;
// 	unset(&env, args);
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
// 	args[0] = ft_strdup("Var1=Value1");
// 	args[1] = NULL;
// 	unset(&env, args);
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
// 	args[0] = ft_strdup("Var2");
// 	args[1] = ft_strdup("Var3");
// 	args[2] = NULL;
// 	unset(&env, args);
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
// 	args[0] = ft_strdup("Var2=Value2");
// 	args[1] = ft_strdup("Var3");
// 	args[2] = NULL;
// 	unset(&env, args);
// 	arprint(env);
// 	arfree(env);
// 	arfree(args);
// }
//

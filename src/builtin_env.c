/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:23:04 by iubieta-          #+#    #+#             */
/*   Updated: 2025/03/23 19:15:04 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env(char **env)
{
	if (!env)
	{
		printf("env: env array doesnt exist\n");
		return (1);
	}
	while (*env)
	{
		if (ft_strchr(*env, '='))
			printf("%s\n", *env);
		else
		{
			printf("%s\n", *env);
			printf("env: string with invalid format on env array\n");
		}
		env++;
	}
	return (0);
}

// TEST
// int	main()
// {
// 	char	**env;
//
// 	printf("\n--Test 1--\n");
// 	arprint(NULL);
// 	env(NULL);
//
// 	printf("\n--Test 2--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = NULL;
// 	arprint(env);
// 	env(env);
// 	arfree(env);
//
// 	printf("\n--Test 3--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	arprint(env);
// 	env(env);
// 	arfree(env);
//
// 	printf("\n--Test 4--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = ft_strdup("Var2Value2");
// 	env[2] = NULL;
// 	arprint(env);
// 	env(env);
// 	arfree(env);
//
// 	printf("\n--Test 5--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = ft_strdup("Var2=Value2");
// 	env[2] = ft_strdup("Var3=Value3");
// 	env[3] = ft_strdup("Var4=Value4");
// 	env[4] = NULL;
// 	arprint(env);
// 	env(env);
// 	arfree(env);
// 	
// 	printf("\n--Test 6--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = ft_strdup("Var2Value2");
// 	env[2] = ft_strdup("Var3Value3");
// 	env[3] = ft_strdup("Var4=Value4");
// 	env[4] = NULL;
// 	arprint(env);
// 	env(env);
// 	arfree(env);
//
// }

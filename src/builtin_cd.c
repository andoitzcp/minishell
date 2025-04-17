/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:27:13 by iubieta-          #+#    #+#             */
/*   Updated: 2025/03/23 19:36:05 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd(char **args)
{
	char	*path;

	if (!args || !args[1])
	{
		path = getenv("HOME");
		chdir(path);
		return (0);
	}
	if (args[2])
	{
		printf("cd: too many arguments\n");
		return (1);
	}
	path = args[1];
	if (chdir (path) == -1)
	{
		perror("cd: ");
		return (1);
	}
	return (0);
}

// TEST
// int main() 
// {
// 	char *home[] = {"cd", "/home", NULL};
// 	char *args[1024];
// 
// 	// Comprobacion sin argumentos
// 	printf("--TEST 1--\n");
// 	cd(home);
// 	pwd(NULL);
// 	cd(NULL);
// 	pwd(NULL);
// 
// 	//Comprobacion con argumentos
// 	printf("--TEST 2--\n");
// 	cd(home);
// 	pwd(NULL);
// 	args[0] = "cd";
// 	cd(args);
// 	pwd(NULL);
// 
// 	printf("--TEST 3--\n");
// 	cd(home);
// 	pwd(NULL);
// 	args[0] = "cd";
// 	args[1] = NULL;
// 	cd(args);
// 	pwd(NULL);
// 
// 	printf("--TEST 4--\n");
// 	cd(home);
// 	pwd(NULL);
// 	args[0] = "cd";
// 	args[1] = ".";
// 	args[2] = NULL;
// 	cd(args);
// 	pwd(NULL);
// 
// 	printf("--TEST 5--\n");
// 	cd(home);
// 	pwd(NULL);
// 	args[0] = "cd";
// 	args[1] = "..";
// 	args[2] = NULL;
// 	cd(args);
// 	pwd(NULL);
// 
// 	printf("--TEST 6--\n");
// 	cd(home);
// 	pwd(NULL);
// 	args[0] = "cd";
// 	args[1] = "/etc";
// 	args[2] = NULL;
// 	cd(args);
// 	pwd(NULL);
// 
// 	printf("--TEST 7--\n");
// 	cd(home);
// 	pwd(NULL);
// 	args[0] = "cd";
// 	args[1] = "sadjhla";
// 	args[2] = NULL;
// 	cd(args);
// 	pwd(NULL);
// 
// 	printf("--TEST 8--\n");
// 	cd(home);
// 	pwd(NULL);
// 	args[0] = "cd";
// 	args[1] = "/home";
// 	args[2] = "sadjhla";
// 	args[3] = NULL;
// 	cd(args);
// 	pwd(NULL);
// 
// }

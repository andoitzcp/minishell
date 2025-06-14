/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:16:20 by iubieta-          #+#    #+#             */
/*   Updated: 2025/06/06 10:13:17 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(void)
{
	char	*current_dir;

	current_dir = getcwd(NULL, 0);
	printf("%s\n", current_dir);
	return (0);
}

// TEST
// int main()
// {
// 	char *args[3];
// 
// 	printf("--TEST 1--\n");
// 	pwd(NULL);
// 
// 	printf("--TEST 2--\n");
// 	args[0] = NULL;
// 	pwd(args);
// 
// 	printf("--TEST 3--\n");
// 	args[0] = "pwd";
// 	args[1] = NULL;
// 	pwd(args);
// 
// 	printf("--TEST 4--\n");
// 	args[0] = "pwd";
// 	args[1] = ".";
// 	args[2] = NULL;
// 	pwd(args);
// 
// }

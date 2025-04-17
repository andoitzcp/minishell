/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:36:04 by iubieta-          #+#    #+#             */
/*   Updated: 2025/03/08 15:18:26 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

char	*findbin(char *bin)
{
	char	*path;
	char	**paths;
	int		i;

	 // printf("findbin: bin = %s\n", bin);
	if (access(bin, X_OK) == 0)
		return (bin);
	bin = ft_strjoin("/", bin);
	path = getenv("PATH");
	paths = ft_split(path, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], bin);
		// printf("findbin: path = %s\n", path);
		if (access(path, X_OK) == 0)
			return (ft_free2parray(paths), paths = NULL, path); // Free fuera de la funcion
		free(path);
		i++;
	}
	return (ft_free2parray(paths), paths = NULL, NULL);
}
// TEST 
//
// int	main()
// {
// 	printf("Ejecutable: %s\n", findbin("./a.out"));
// 	printf("Ejecutable: %s\n", findbin("../minishell"));
// 	printf("Ejecutable: %s\n", findbin("/pwd"));
// 	printf("Ejecutable: %s\n", findbin("/vim"));
// 	printf("Ejecutable: %s\n", findbin("/nada"));
// }

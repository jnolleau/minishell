/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grim <grim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 12:14:58 by grim              #+#    #+#             */
/*   Updated: 2020/07/01 17:23:16 by grim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mshell.h"

int		ft_handle(char *buf, t_list **env)
{
	t_list	*pipe_list;

	pipe_list = NULL;
	if (ft_parse(buf, *env, &pipe_list) == ERROR)
		return(ERROR);
	ft_traitement(pipe_list, env);
	ft_lstclear(&pipe_list, &del_pipe);
	return (0);
}

int		main()
{
	t_list	*env;
	int		ret;
	char	*buf;

	buf = malloc(BUF_SIZE + 1);
	ft_init(&env);
	// ft_print_env(env);
	// int i = 0;
	// while (i < 1)
	while (1)
	{
		ft_putstr_fd("cmd: ", 1);
		ret = read(1, buf, BUF_SIZE);
		// printf("ret: %d\n", ret);
		buf[ret - 1] = 0; // on a un \n qui s'ajoute à la fin du buffer, dont on ne veut pas
		ft_handle(buf, &env);
		// i++;
	}
	ft_lstclear(&env, &del_key_val);
	free(buf);
}

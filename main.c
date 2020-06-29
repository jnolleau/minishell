/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grim <grim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 12:14:58 by grim              #+#    #+#             */
/*   Updated: 2020/06/29 11:04:13 by grim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mshell.h"

int		ft_handle(char *buf, t_list **env)
{
	t_list	*cmd;

	// il faudrait parser ici la commande, et set des flags en fonction (chercher les '<', '>>'...)
	// cmd = ft_split(buf, ' ');
	// print_cmd(cmd);
	if (ft_parse_fsm(buf, *env) == ERROR)
		return(ERROR);
	(void)cmd;
	// ft_traitement(cmd, env);
	// ft_lstclear(&cmd, &del_cmd);
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

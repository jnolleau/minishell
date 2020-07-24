/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_print_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grim <grim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 17:29:46 by grim              #+#    #+#             */
/*   Updated: 2020/07/24 15:32:29 by grim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mshell.h"

void	print_pipe_bufs(t_list *pipe_list)
{
	t_list	*cmd_list;
	t_cmd	*cmd;

	cmd_list = (t_list*)pipe_list->content;
	while (cmd_list)
	{
		cmd = (t_cmd*)cmd_list->content;
		printf("buf: [%s]\n", cmd->buf);
		cmd_list = cmd_list->next;
	}
}

void	ft_print_redir(t_list *redir_list)
{
	t_redir *redir;
	int i;

	i = 0;
	while (redir_list)
	{
		redir = (t_redir*)redir_list->content;
		if (redir->state == REDIR_IN)
		{
			printf(" Redir_IN");
			printf(" file: [%s]\n", redir->file);
		}
		if (redir->state == REDIR_OUT)
		{
			printf(" Redir_OUT");
			printf(" file: [%s]\n", redir->file);
		}
		if (redir->state == REDIR_APPEND)
		{
			printf(" Redir_APPEND");
			printf(" file: [%s]\n", redir->file);
		}
		i++;
		redir_list = redir_list->next;
	}
	
}

void	ft_print_flag_redir(t_list *flag)
{
	int *val;
	
	while (flag)
	{
		val = (int *)flag->content;
		printf(" flag_$_redir: %d\n", *val);	
		flag = flag->next;
	}
}

void	ft_print_flag(t_list *flag)
{
	int *val;
	
	while (flag)
	{
		val = (int *)flag->content;
		printf(" flag_$_argv: %d\n", *val);	
		flag = flag->next;
	}
}

void	ft_print_argv_list(t_list *argv_list)
{
	char *argv;
	int i;
	
	i = 0;
	while (argv_list)
	{
		argv = (char *)argv_list->content;
		printf(" list_argv[%d]: %s\n", i, argv);	
		argv_list = argv_list->next;
		i++;
	}
}

void	print_pipe_argv_redirs(t_list *pipe_list)
{
	t_list	*cmd_list;
	t_cmd	*cmd;
	int		i;
	int		num;

	num = 0;
	cmd_list = (t_list*)pipe_list->content;
	while (cmd_list)
	{
		printf("CMD %d > \n", num);
		cmd = (t_cmd*)cmd_list->content;
		i = 0;
		while (cmd->argv[i])
		{
			printf(" argv[%d]: [%s]\n", i, cmd->argv[i]);
			i++;
		}
		if (cmd->flag)
			ft_print_flag(cmd->flag);
		if (cmd->redir)
			ft_print_redir(cmd->redir);
		if (cmd->flag_redir)
			ft_print_flag_redir(cmd->flag_redir);
		if (cmd->argv_list)
			ft_print_argv_list(cmd->argv_list);
		printf(" cmdpath: %s\n", cmd->cmd_path);
		num++;
		cmd_list = cmd_list->next;
	}
}

void	print_commands(t_list *pipe_list)
{
	int i;

	i = 0;
	printf("\nPRINTING COMMAND\n");
	while (pipe_list)
	{
		printf("PIPE %d >> \n", i);
		// print_pipe_bufs(pipe_list);
		print_pipe_argv_redirs(pipe_list);
		pipe_list = pipe_list->next;
		i++;
	}
}

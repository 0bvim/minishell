#include "../../includes/minishell.h"

extern char	**environ;

void	exec_single_command(t_ast *root)
{
	t_element	*el;
	t_cmd		*cmd;
	pid_t		fork;

	cmd = 0;
	cmd->paths = get_paths();
	cmd->path = 
	if (root->left)
		exec_single_command(root->left);
	if (root->right)
		exec_single_command(root->right);
	if (root->exec)
	{
		el = root->exec->first;
		while (el)
		{
			fork = fork();
			cmd->paths = get_paths();
			if (fork == 0)
			{
				cmd->cmds = get_command(((t_token *)el->content)->str);
				execve()

			}
			wait(NULL);
			printf("%s ", ((t_token *)el->content)->str);
			el = el->next;
		}
		printf("\n");
	}
}

char	*validate_path(char *final, char **paths)
{
	char	*temp;
	char	*cmd;
	int		i;

	if (access(final, F_OK | X_OK) == 0)
	{
		cmd = ft_strdup(final);
		return (cmd);
	}
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		cmd = ft_strjoin(temp, final);
		ft_free_str(temp);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		ft_free_str(cmd);
		i++;
	}
	return (NULL);
}

char	**get_command(char *argv)
{
	int			i;
	char		**cmds;

	i = ft_strlen(argv);
	while (argv[i] != 0x27 && argv[i] != 0x22 && i != 0)
		--i;
	if (i == 0)
		cmds = ft_split(argv, ' ');
	else
	{
		if (argv[i] == 39)
			cmds = ft_split(argv, 0x27);
		else
			cmds = ft_split(argv, 0x22);
	}
	return (cmds);
}

char	*get_first_command(const char *cmd)
{
	char	*temp;
	int		len;

	if (!cmd)
		return (NULL);
	while (cmd[len] != ' ' || cmd[len] != '\0')
		len++;
	temp = malloc(len + 1);
	ft_strlcpy(temp, dest, len);
	return (temp);
}

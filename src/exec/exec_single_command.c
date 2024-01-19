#include "../../includes/minishell.h"

extern char	**environ;

void	exec_single_command(t_ast *root)
{
	t_element	*el;
	t_cmd		*cmd;
	pid_t		fork;

	if (root->left)
		exec_single_command(root->left);
	if (root->right)
		exec_single_command(root->right);
	if (root->exec)
	{
		el = root->exec->first;
		cmd->cmds
		while (el)
		{
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

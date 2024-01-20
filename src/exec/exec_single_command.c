#include "../../includes/minishell.h"

extern char	**environ;

void	ft_free_str(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
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

	len = 0;
	if (!cmd)
		return (NULL);
	while (cmd[len] != ' ' && cmd[len] != '\0')
		len++;
	temp = malloc(++len);
	ft_strlcpy(temp, cmd, len);
	return (temp);
}

void	exec_single_command(t_ast *root)
{
	t_element	*el;
	t_cmd		*cmd;
	char		*tmp;

	cmd = malloc(sizeof(t_cmd *) * 1);
	cmd->paths = get_paths();
	if (root->left)
		exec_single_command(root->left);
	if (root->right)
		exec_single_command(root->right);
	if (root->exec)
	{
		el = root->exec->first;
		tmp = concat_args(el);
		// printf("%s\n", tmp);
		cmd->args = get_command(tmp);
		cmd->path = validate_path(cmd->args[0], cmd->paths);
		// if (execve(cmd->path, cmd->args, environ) < 0)
		// 	exit(1);
	}
}

// need to concat with one space betwen each word, or input in one **char in each position
char	*concat_args(t_element *el)
{
	size_t	words;

	words = ft_lstsize((t_list *)el);
	printf("%zu\n", words);
	return (NULL);
}

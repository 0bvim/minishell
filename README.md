![eng](../../../stuff/blob/main/USA-icon.png) [![pt-BR](../../../stuff/blob/main/Brazil-icon.png)](README.pt-BR.md)

# minishell
This project is about creating a simple shell.

### Mandatory part
We need to implement a bash that handle simple commands like

1. redirections
	- `output (ls > file)`
	- `append (echo Hail >> file)`
	- `input (< Makefile cat)`
	- `heredoc (cat << delimiter_to_stop)`
2. pipes
	- `cat Makefile | grep CFLAGS | tr ' ' '#' | wc`
3. command history
4. environment variables
5. signals
	- `ctrl-C`
	- `ctrl-D`
	- `ctrl-\`
6. $? (expand to the exit status of the most recently executed foregrund pipeline)
7. builtins
	- `echo with option -n`
	- `cd with only a relative or absolute path`
	- `pwd with no options`
	- `export with no options`
	- `unset with no options`
	- `env with no options or arguments`
	- `exit with no options`

### under construction.

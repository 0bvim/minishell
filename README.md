![eng](../../../stuff/blob/main/USA-icon.png) [![pt-BR](../../../stuff/blob/main/Brazil-icon.png)](README.pt-BR.md)

# minishell
This project is about creating a simple shell.

## Table of Contents
- [Mandatory](#mandatory-part)
- [Bonus](#bonus-part)
- [Download](#download)
- [License](./LICENSE)

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
6. $? (expand to the exit status of the most recently executed foreground pipeline)
7. builtins
	- `echo with option -n`
	- `cd with only a relative or absolute path`
	- `pwd with no options`
	- `export with no options`
	- `unset with no options`
	- `env with no options or arguments`
	- `exit with no options`

### Bonus part
- Our program has to implement
	- `&& and || with parenthesis for priorities.`
	- `Wildcards * should work for the current working directory.`

```bash
# && and || examples
echo Hello && echo Bye
wrong_command || echo right_command
```

```bash
# Wildcard example
ls *
cat *c
```

## Download
```ssh
git clone git@github.com:vinicius-f-pereira/minishell.git
```
Use `make` or `make bonus` and follow instructions [`Here`](#mandatory-part)

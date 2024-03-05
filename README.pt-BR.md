[![eng](../../../stuff/blob/main/USA-icon.png)](README.md) ![pt-BR](../../../stuff/blob/main/Brazil-icon.png)

# minishell
Esse projeto e sobre criar o seu proprio shell.

## Tabela de Conteúdo
- [Mandatorio](#mandatory-part)
- [Bonus](#bonus-part)
- [Download](#download)
- [Licença](./LICENSE)

## Mandatory part
Nos precisamos implementar um bash que execute os comandos a seguir

1. redirecionamento
	- `saida (ls > arquivo)`
	- `acrescentar (echo Hail >> arquivo)`
	- `entrada (< Makefile cat)`
	- `heredoc (cat << delimitador_de_parada)`
2. pipes
	- `cat Makefile | grep CFLAGS | tr ' ' '#' | wc`
3. historico de comandos
4. variaveis ambiente
5. sinais
	- `ctrl-C`
	- `ctrl-D`
	- `ctrl-\`
6. $? (expande para o codigo de estado de saida mais recente executado na linha de comando do primeiro plano.)
7. builtins
	- `echo com a flag -n`
	- `cd apenas com caminho relativo e absoluto`
	- `pwd sem flags`
	- `export sem flags`
	- `unset sem flags`
	- `env sem flags e argumentos`
	- `exit flags`

### Bonus part
- Nosso programa precisa executar
	- `&& e || com parenteses para prioridades.`
	- `Wildcards * devem funcionar para o diretorio atual.`

```bash
# && and || examples
echo oi && echo Tchau
comando_errado || echo comando_da_direita
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
Use `make` or `make bonus` e siga as instrucoes [`Here`](#mandatory-part)

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 12:05:38 by vde-frei          #+#    #+#              #
#    Updated: 2023/11/15 01:42:10 by nivicius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SHELL := /bin/bash
COUNT := 0
SLEEP := sleep 0.5

BLACK  		 = \033[0;30m
RED    		 = \033[0;31m
GREEN  		 = \033[0;32m
YELLOW 		 = \033[0;33m
BLUE   		 = \033[0;34m
MAGENTA		 = \033[0;35m
CYAN   		 = \033[0;36m
WHITE  		 = \033[0;37m
RESET  		 = \033[0m

MANDATORY = Static library compiled
LBONUS =
CLEAN = Objects delete
FCLEAN = Static library delete
LIBNAME = libft
BLIBNAME =
COMP = Compiling

DFLAGS = -Wall -Wextra -Werror -g3 # TO DEBBUG
CFLAGS = -Wall -Werror -Wextra -O3 -fomit-frame-pointer -finline-functions # TO IMPROVE PERFORMANCE
ARFLAGS = rcs

SRC = src
BONUS =
INC = includes
OBJ = obj

INCLUDES = -I$(INC)/

CFILES = ft_atol.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_strlen.c ft_tolower.c ft_toupper.c ft_memset.c ft_bzero.c \
	ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strncmp.c \
	ft_strchr.c ft_strrchr.c ft_strdup.c ft_memchr.c ft_strnstr.c \
	ft_memcmp.c ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_itoa.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_strmapi.c ft_striteri.c ft_lstnew.c  ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	ft_lstmap.c ft_free_split.c get_next_line_bonus.c get_next_line_utils_bonus.c \
	ft_free_str.c

OBJECT =  $(patsubst %, $(OBJ)/%, $(notdir $(CFILES:.c=.o)))

ifdef WITH_DEBBUG
	CFLAGS = $(DFLAGS)
endif

all: $(OBJ) $(NAME)

$(NAME): $(OBJECT)
	@$(AR) $(ARFLAGS) $@ $?
	@$(SLEEP)
	@printf "\n$(MAGENTA)$(MANDATORY)\n$(RESET)"

$(OBJ):
	@mkdir -p $(OBJ)

$(OBJ)/%.o: $(SRC)/%.c
	@$(eval COUNT=$(shell expr $(COUNT) + 1))
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(GREEN)$(LIBNAME) $(COMP) %d%%\r$(RESET)" $$(echo $$(($(COUNT) * 100 / $(words $(CFILES)))))

clean:
	@$(RM) -rf $(OBJ)
	@$(SLEEP)
	@printf "$(RED)$(CLEAN)$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@$(SLEEP)
	@printf "$(RED)$(FCLEAN)$(RESET)\n"

re: fclean all

debbug:
	@make WITH_DEBBUG=TRUE --no-print-directory

.PHONY: all clean fclean re debbug

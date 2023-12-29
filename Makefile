# program name #
NAME = minishell

# shell #
SHELL := /bin/bash

# misc #
COUNT := 0
SLEEP := sleep 0.2

# colors #
DEFAULT=\033[39m
BLACK=\033[30m
DARK_RED=\033[31m
DARK_GREEN=\033[32m
DARK_YELLOW=\033[33m
DARK_BLUE=\033[34m
DARK_MAGENTA=\033[35m
DARK_CYAN=\033[36m
LIGHT_GRAY=\033[37m
DARK_GRAY=\033[90m
RED=\033[91m
GREEN=\033[92m
ORANGE=\033[93m
BLUE=\033[94m
MAGENTA=\033[95m
CYAN=\033[96m
WHITE=\033[97m
BG_DEFAULT=\033[49m
BG_BLACK=\033[40m
BG_DARK_RED=\033[41m
BG_DARK_GREEN=\033[42m
BG_DARK_YELLOW=\033[43m
BG_DARK_BLUE=\033[44m
BG_DARK_MAGENTA=\033[45m
BG_DARK_CYAN=\033[46m
BG_LIGHT_GRAY=\033[47m
BG_DARK_GRAY=\033[100m
BG_RED=\033[101m
BG_GREEN=\033[102m
BG_ORANGE=\033[103m
BG_BLUE=\033[104m
BG_MAGENTA=\033[105m
BG_CYAN=\033[106m
BG_WHITE=\033[107m
RESET=\033[0m

# messages #
MANDATORY = Program compiled
LBONUS = Bonus Program compiled
CLEAN = Objects delete
FCLEAN = Program delete
LIBNAME = minishell
BLIBNAME = minishell_bonus
COMP = Compiling

# debug and normal flags #
DFLAGS = -Wall -Wextra -Werror -g3 # TO DEBBUG
CFLAGS = -Wall -Werror -Wextra -g3 -Ofast -flto -MD -MP # FOR DEPENDENCIES
LFLAGS = -march=native # TO OPTIMIZE FOR SPECIFIC ARCHITECTURE
FFLAGS = -lreadline # FLAGS THAT ONLY WORK AT THE END OF LINE (AFTER OBJECTS)

# paths #
SRC = src
BONUS = $(SRC)/bonus
INC = includes
OBJ = obj

# files path #
ENTRANCE = $(SRC)/entrance
PARSER = $(SRC)/parser

# libs #
INCLUDES = -I$(INC)/ -Ilib/libft/includes/
LINCLUDES = -L$(LIBFT_PATH) -lft

LIBFT = lib/libft/libft.a
LIBFT_PATH = lib/libft

# main #
MAIN_SRC = $(ENTRANCE)/minishell.c 
BONUS_SRC = $(addprefix $(BONUS)/, )

# files mandatory #
CFILES = $(addprefix $(ENTRANCE)/, )
CFILES += $(addprefix $(PARSER)/, )

VAL = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind-out.txt
VAL_TXT = valgrind-out.txt

# obj dir #
OBJECT = $(CFILES:%.c=$(OBJ)/%.o)
BIN_OBJ = $(MAIN_SRC:%.c=$(OBJ)/%.o)

# define bonus #
ifdef WITH_BONUS
	NAME = $(BLIBNAME)
	MAIN_SRC = $(BONUS_SRC)
	compile = compile_bonus
	BIN_OBJ = $(BONUS_SRC:%.c=$(OBJ)/%.o)
	MANDATORY = $(LBONUS)
	MAGENTA = $(YELLOW)
	LIBNAME = $(BLIBNAME)
endif


# define debbug #
ifdef WITH_DEBBUG
	CFLAGS = $(DFLAGS)
endif

# functions #
define create_objects_dir
	mkdir -p $(dir $@)
endef

define compile
	$(CC) -o $(NAME) $(CFLAGS) $(LFLAGS) $(INCLUDES) $(LINCLUDES) $(OBJECT) $(BIN_OBJ) $(LIBFT) $(FFLAGS)
	$(SLEEP)
	printf "\n$(MAGENTA)$(MANDATORY)\n$(RESET)"
endef

define compile_bonus
	$(CC) -o $(NAME) $(CFLAGS) $(LFLAGS) $(INCLUDES) $(LINCLUDES) $(OBJECT) $(BIN_OBJ) $(LIBFT)
	$(SLEEP)
	printf "\n$(MAGENTA)$(MANDATORY)\n$(RESET)"
endef

define compile_source
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	$(MAKE) -sC $(LIBFT_PATH)
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<
	printf "$(GREEN)$(LIBNAME) $(COMP) %d%%\r$(RESET)" $$(echo $$(($(COUNT) * 100 / $(words $(CFILES)))))
endef

define clean
	$(MAKE) fclean -sC $(LIBFT_PATH)
	$(RM) -rf $(OBJ)/ && $(RM) -rf $(VAL_TXT)
	$(SLEEP)
	printf "$(RED)$(CLEAN)$(RESET)\n"
endef

define fclean
	$(call eraseBins)
	@$(SLEEP)
	@printf "$(RED)$(FCLEAN)$(RESET)\n"
endef

define bonus
	@make WITH_BONUS=TRUE -s
endef

define debug
	$(call clean)
	$(call fclean)
	$(MAKE) WITH_DEBBUG=TRUE -s
endef

define eraseBins
	$(if $(NAME),@$(RM) $(NAME))
	$(if $(BLIBNAME),@$(RM) $(BLIBNAME))
endef

define help
	echo -e "${BG_DARK_GREEN}${ORANGE}Available targets:${RESET}"
	echo -e "${BG_DARK_GREEN}${ORANGE}all:${RESET}${LIGHT_GRAY}Build push swap${RESET}"
	echo -e "${BG_DARK_GREEN}${ORANGE}both:${RESET}${LIGHT_GRAY}Build push swap and checker${RESET}"
	echo -e "${BG_DARK_GREEN}${ORANGE}bonus:${RESET}${LIGHT_GRAY}Build checker${RESET}"
	echo -e "${BG_DARK_GREEN}${ORANGE}re:${RESET}${LIGHT_GRAY}Rebuild the program${RESET}"
	echo -e "${BG_RED}${ORANGE}clean:${RESET}${LIGHT_GRAY}Remove the object files${RESET}"
	echo -e "${BG_RED}${ORANGE}fclean:${RESET}${LIGHT_GRAY}Remove the program and the object files${RESET}"
	echo -e "${BG_BLUE}${ORANGE}debug:${RESET}${LIGHT_GRAY}Build the program with debugging information${RESET}"
	echo -e "${BG_BLUE}${ORANGE}case:${RESET}${LIGHT_GRAY}Show numbers with best and worst case${RESET}"
	echo -e "${BG_BLUE}${ORANGE}test_nb:${RESET}${LIGHT_GRAY}Test the program with provided list length${RESET}"
endef

# rules #
all: $(NAME)

$(NAME): $(OBJECT) $(BIN_OBJ)
	$(call create_objects_dir)
	$(call compile)

$(OBJ)/%.o: %.c
	$(call create_objects_dir)
	$(call compile_source)

-include $(OBJECT:.o=.d)

clean:
	$(call clean)

fclean: clean
	$(call fclean)

re: fclean all

bonus:
	$(call bonus)

debug:
	$(call debug)

help:
	$(call help)

.PHONY: all bonus clean fclean re debug help Makefile
.DEFAULT_GOAL := all
.SILENT:

#≻───░⋆ ✪ DEFAULTS ✪ ⋆░──────────────────────────────────────────────────────≺#
NAME			=	libft.a
LIB				=	libft.a
AR				=	ar
AR_FLAGS		=	rcs
CC				=	cc
CC_FLAGS 		=	-Wall -Werror -Wextra -O3

#≻───░⋆ ✪ PROJECT DIRECTORIES & FILES ✪ ⋆░───────────────────────────────────≺#
INCLUDES		=	-I./include
INCLUDES_FILES	=	get_next_line.h				\
					libft.h
SRC_FILES		=	ft_abs.c					\
					ft_atof.c					\
					ft_atoi.c					\
					ft_atoll.c					\
					ft_bzero.c					\
					ft_calloc.c					\
					ft_isalnum.c				\
					ft_isalpha.c				\
					ft_isascii.c				\
					ft_isdigit.c				\
					ft_isprint.c				\
					ft_isspace.c				\
					ft_itoa.c					\
					ft_itoa_base.c				\
					ft_lstadd_back.c			\
					ft_lstadd_front.c			\
					ft_lstclear.c				\
					ft_lstdelone.c				\
					ft_lstiter.c				\
					ft_lstmap.c					\
					ft_lstnewelement.c			\
					ft_lstpickel.c				\
					ft_lstpop.c					\
					ft_lstsecondlast.c			\
					ft_lstsize.c				\
					ft_memchr.c					\
					ft_memcmp.c					\
					ft_memcpy.c					\
					ft_memmove.c				\
					ft_memset.c					\
					ft_putchar_fd.c				\
					ft_putendl_fd.c				\
					ft_putnbr_fd.c				\
					ft_putstr_fd.c				\
					ft_split.c					\
					ft_strchr.c					\
					ft_strdup.c					\
					ft_strisinteger.c			\
					ft_strisnumber.c			\
					ft_striteri.c				\
					ft_strjoin.c				\
					ft_strlcat.c				\
					ft_strlcpy.c				\
					ft_strlen.c					\
					ft_strmapi.c				\
					ft_strmerge.c				\
					ft_strncmp.c				\
					ft_strnstr.c				\
					ft_strrchr.c				\
					ft_strtolower.c				\
					ft_strtoupper.c				\
					ft_strtrim.c				\
					ft_substr.c					\
					ft_tolower.c				\
					ft_toupper.c				\
					ft_ultoa_base.c				\
					ft_utoa_base.c				\
					get_next_line.c
SRC_DIR			=	src
BUILD_DIR		=	build
SRCS			=	$(addprefix ./$(SRC_DIR)/, $(SRC_FILES))
OBJS 			=	$(addprefix ./$(BUILD_DIR)/, $(SRC_FILES:.c=.o))

#≻───░⋆ ✪ COLORS ✪ ⋆░────────────────────────────────────────────────────────≺#
RED				=	\033[0;31m
YELLOW			=	\033[0;33m
BLUE			=	\033[0;34m
MAGENTA			=	\033[0;35m
CYAN			=	\033[0;36m
WHITE			=	\033[0;37m
GREEN			=	\033[0;32m
DEFAULT 		=	\033[0:0m

#≻───░⋆ ✪ RULES ✪ ⋆░─────────────────────────────────────────────────────────≺#
.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : $(BUILD_DIR) $(OBJS)
	@ printf "$(GREEN)$(LIB)$(DEFAULT) successfully generated\n"

$(BUILD_DIR):
	@ mkdir $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@ printf "$(MAGENTA)$< $(BLUE)->$(GREEN) $@$(DEFAULT)\n"
	@ $(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@
	@ $(AR) $(AR_FLAGS) $(LIB) $@

clean:
	@ rm -rf $(BUILD_DIR)
	@ printf "build directory have been cleaned\n"

fclean: clean
	@ rm -f $(LIB)
	@ printf "$(MAGENTA)$(LIB)$(DEFAULT) have been cleaned\n"

re: fclean all

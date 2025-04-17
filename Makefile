# Variables

NAME	= minishell
HEADERS	= src/minishell.h
INCLUDE = inc/
SRC_DIR	= src/
OBJ_DIR	= obj/
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g
RM		= rm -f

LIBFT		= $(addprefix $(INCLUDE), libft/)

LIBFT_A		= $(addprefix $(LIBFT), libft.a)

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

# signals

SRC_FILES	=	minishell init signals\
				tokenizer token_utils \
				parser redir_types \
				redir_types2 \
				str_utils ar_utils \
				tree_utils \
				exec exec_utils \
				builtin_pwd builtin_cd \
				builtin_echo \
				builtin_exit \
				builtin_env builtin_export builtin_unset env_utils \
				handle_redir \
				prompt


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJF		= .cache_exists

all:		$(NAME)

$(NAME):	$(OBJ) $(LIBFT_A)
			@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -o $(NAME) -lreadline
			@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

parse:		$(OBJ) $(LIBFT_A)
			@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -o $(NAME) -lreadline
			@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

$(LIBFT_A):
			@$(MAKE) -s -C $(LIBFT)
			@echo "Compiled $(LIBFT_A)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -f $(LIBFT)/$(LIBFT_A)
			@echo "$(CYAN)$(LIBFT) executable files succesfully cleaned!$(DEF_COLOR)"
			@$(RM) -rf $(OBJ_DIR)
			@echo "$(BLUE)$(NAME) object files succesfully cleaned!$(DEF_COLOR)"
			@$(RM) -f $(SRC_DIR)/minishell.h.gch

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "$(CYAN)$(NAME) executable files succesfully cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Everything was cleaned and the rebuilt for pipex!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm

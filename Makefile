NAME            = philo

LIBFT           = $(LIBFT_DIR)/libft.a

CC              = cc
CFLAGS          = -Wall -Wextra -Werror -g -pthread

RM              = rm -rf
OBJ_DIR         = obj

SRCS            = src/philo.c 			src/utils/print_err.c	src/check_arg.c	src/init_data.c	\
				  src/utils/ft_atoi.c	src/utils/time_utils.c	src/utils/ft_init_mutex.c		\
				  src/utils/ft_clean.c
OBJS            = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

GREEN           = \033[0;32m
RED             = \033[0;31m
RESET           = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo -e "$(GREEN)Compiling $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning objects..."
	$(RM) $(OBJ_DIR)

fclean: clean
	@echo "Cleaning executable..."
	$(RM) $(NAME)

norm:
	@ERR_COUNT=$$(norminette src/ | grep "Error" | wc -l); \
	if [ $$ERR_COUNT -eq 0 ]; then \
		echo -e "$(GREEN)Norminette: TOUT EST PARFAIT !$(RESET)"; \
	else \
		echo -e "$(RED)Norminette: ERREURS TROUVÉES :$(RESET)"; \
		norminette src/ | grep "Error"; \
	fi

re: fclean all

.PHONY: all clean fclean re norm
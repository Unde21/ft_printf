# Nom du projet
NAME = libftprintf.a

CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFFLAGS := -MD -MP -MF
DEBUGFLAGS := -fsanitize=address -g3

RM := rm -rf
AR := ar -rcs

SRC_DIR := srcs/
OBJ_DIR := .objs/
DEP_DIR := .deps/
LIBFT_DIR := libft/

INCS := -I . -I $(LIBFT_DIR)

SRCS := $(shell find srcs -name "*.c")

OBJS := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
DEPS := $(SRCS:$(SRC_DIR)%.c=$(DEP_DIR)%.d)

BONUS_SRCS :=
BONUS_OBJS := $(BONUS_SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

LIBFT := $(LIBFT_DIR)libft.a

BOLD := \033[1m
GREEN := \033[0;32m
RED := \033[0;31m
BLUE := \033[0;34m
END := \033[0m


.PHONY: all clean fclean re bonus debug libft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)$(BOLD)$(NAME) created successfully!$(END)"


$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR) $(DEP_DIR)
	@mkdir -p $(dir $@) $(dir $(DEP_DIR)$*)
	@$(CC) $(CFLAGS) $(INCS) $(CPPFFLAGS) $(DEP_DIR)$*.d -c $< -o $@

$(OBJ_DIR) $(DEP_DIR):
	@mkdir -p $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

debug: CFLAGS += $(DEBUGFLAGS)
debug: re

bonus: SRCS += $(BONUS_SRCS)
bonus: all

clean:
	@$(RM) $(OBJ_DIR) $(DEP_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(RED)$(BOLD)Objects cleaned$(END)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(RED)$(BOLD)Everything cleaned$(END)"

re: fclean all

-include $(DEPS)

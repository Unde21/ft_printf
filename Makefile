NAME = libftprintf.a

CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
CPPFFLAGS := -MD -MP -MF

RM := rm -rf
AR := ar -rcs

SRC_DIR := srcs/
OBJ_DIR := .objs/
DEP_DIR := .deps/
LIBFT_DIR := libft/

INCS := -I. -I$(LIBFT_DIR)

SRCS := srcs/ft_printf.c \
	srcs/check_flags.c \
	srcs/manage_flags_nb.c \
	srcs/manage_flags_u_nb.c \
	srcs/manageflag_hex.c \
	srcs/print_c.c \
	srcs/print_format.c \
	srcs/print_hex.c \
	srcs/print_nb.c \
	srcs/print_p.c \
	srcs/print_s.c \
	srcs/print_u.c \
	srcs/utils.c \

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


.PHONY: all clean fclean re bonus libft

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

NAME = libftprintf.a

CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFFLAGS := -MD -MP -MF

RM := rm -rf
AR := ar -rcs

SRC_DIR := srcs/
SRCB_DIR := srcs_bonus/
OBJ_DIR := .objs/
DEP_DIR := .deps/
OBJB_DIR := .objs_bonus/
DEPB_DIR := .deps_bonus/
LIBFT_DIR := libft/

INCS := -I. -I$(LIBFT_DIR)

SRCS := srcs/ft_printf.c \
	srcs/ft_print_format.c \
	
SRCSB := srcs_bonus/ft_printf.c \
	srcs_bonus/check_flags.c \
	srcs_bonus/manage_flags_nb.c \
	srcs_bonus/manage_flags_u_nb.c \
	srcs_bonus/manageflag_hex.c \
	srcs_bonus/print_c.c \
	srcs_bonus/print_format.c \
	srcs_bonus/print_hex.c \
	srcs_bonus/print_nb.c \
	srcs_bonus/print_p.c \
	srcs_bonus/print_s.c \
	srcs_bonus/print_u.c \
	srcs_bonus/utils.c \
	srcs_bonus/manage_flags_s.c

OBJS := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
OBJSB := $(patsubst $(SRCB_DIR)%.c, $(OBJB_DIR)%.o, $(SRCSB))
DEPS := $(SRCS:$(SRC_DIR)%.c=$(DEP_DIR)%.d)
DEPSB := $(SRCSB:$(SRCB_DIR)%.c=$(DEPB_DIR)%.d)


LIBFT := $(LIBFT_DIR)libft.a

BOLD := \033[1m
GREEN := \033[0;32m
RED := \033[0;31m
BLUE := \033[0;34m
END := \033[0m


.PHONY: all clean fclean re bonus libft FORCE

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(RM) $(NAME)
	@$(RM) $(OBJB_DIR) $(DEPB_DIR)
	@cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)$(BOLD)$(NAME) created successfully!$(END)"


$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR) $(DEP_DIR)
	@mkdir -p $(dir $@) $(dir $(DEP_DIR)$*)
	@$(CC) $(CFLAGS) $(INCS) $(CPPFFLAGS) $(DEP_DIR)$*.d -c $< -o $@

$(OBJ_DIR) $(DEP_DIR):
	@mkdir -p $@


$(OBJB_DIR)%.o: $(SRCB_DIR)%.c | $(OBJB_DIR) $(DEPB_DIR)
	@mkdir -p $(dir $@) $(dir $(DEPB_DIR)$*)
	@$(CC) $(CFLAGS) $(INCS) $(CPPFFLAGS) $(DEPB_DIR)$*.d -c $< -o $@

$(OBJB_DIR) $(DEPB_DIR):
	@mkdir -p $@

$(LIBFT): FORCE
	@$(MAKE) -C $(LIBFT_DIR)

bonus: .bonus

.bonus: $(LIBFT) $(OBJSB)
	$(RM) $(NAME)
	@$(RM) $(OBJ_DIR) $(DEP_DIR)
	@cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJSB)
	@echo "$(GREEN)$(BOLD)$(NAME) created successfully!$(END)"
	@echo "$(BLUE)$(BOLD)$(NAME) made with bonuses$(END)"
	@touch .bonus

FORCE :

clean:
	@$(RM) $(OBJ_DIR) $(DEP_DIR) $(OBJB_DIR) $(DEPB_DIR) .bonus
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(RED)$(BOLD)Objects cleaned$(END)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(RED)$(BOLD)Everything cleaned$(END)"

re: fclean all

-include $(DEPS)
-include $(DEPSB)

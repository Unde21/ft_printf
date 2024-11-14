NAME = libftprintf.a


SRCS = srcs/ft_printf.c \
	srcs/print_format.c \
	srcs/conversions_format.c \

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INC_FILE = ft_printf.h libft//libft.h

CC = cc
CFLAGS = -Wall -Wextra -Werror 


OBJS = $(SRCS:.c=.o)

all: lib $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		cp $(LIBFT) $(NAME)
		ar rcs $(NAME) $(OBJS)

lib:
	make --no-print-directory -C $(LIBFT_DIR)

%.o: %.c $(INC_FILE)
	$(CC) $(CFLAGS) -I . -c $< -o $@

clean:
	rm -f $(OBJS)
	make --no-print-directory -C $(LIBFT_DIR) clean

fclean: clean
		rm -f $(NAME)
		make --no-print-directory -C $(LIBFT_DIR) fclean
re: fclean all

.PHONY: all clean fclean re lib


#SRCS := ft_printf.c \
#
#SRCSB := 
#
#NAME = libftprintf.a
#OBJS_FILE = $(SRCS:.c=.o)
#OBJS = $(addprefix $(OBJS_DIR), $(OBJS_FILE))
#OBJSB_FILE = $(SRCSB:.c=.o)
#OBJSB = $(addprefix $(OBJS_DIR), $(OBJSB_FILE))
#OBJS_DIR = .objs/
#INCS = -I . libft/libft.h
#CC := cc
#CFLAGS := -Wall -Wextra -Werror -fsanitize=address -g3 
#RM := rm -rf
#AR := ar -rcs
#DEPS_FILE = $(SRCS:.c=.d)
#DEPS = $(addprefix $(DEPS_DIR), $(DEPS_FILE))
#CPPFFLAGS = -MD -MP -MF
#DEPS_DIR = .deps/
#LIBFT_DIR = libft
#LIBFT = $(LIBFT_DIR)/libft.a
#
#
#
#
#BOLD = \033[1m
#GREEN=\033[0;32m
#RED=\033[0;31m
#BLUE=\033[0;34m
#COLOR_END=\033[0m
#
#
#all: $(NAME)
#
#$(NAME): $(OBJS)
#	cp $(LIBFT) $(NAME)
#	$(AR) $(NAME) $(OBJS)
#	@echo "$(GREEN)$(BOLD)LIBRARY CREATED: $(NAME)$(COLOR_END)"
#
#libft:
#	make --no-print-directory -C $(LIBFT_DIR)
#
#$(OBJS_DIR)%.o:%.c | $(OBJS_DIR) $(DEPS_DIR) $(INCS)
#	$(CC) $(CFLAGS) $(INCS) $(CPPFFLAGS) $(DEPS_DIR)$*.d -c $< -o $@ 
#
#$(OBJS_DIR) $(DEPS_DIR):
#	mkdir -p $@
#
#clean:
#	$(RM) $(OBJS_DIR) $(DEPS_DIR) .bonus
#	make -C $(LIBFT_DIR)
#	@echo "$(RED)$(BOLD)CLEANED OBJECTS$(COLOR_END)"
#
#fclean: clean
#	$(RM) $(NAME) $(OBJS_DIR)
#	make -C $(LIBFT_DIR)
#	@echo "$(RED)$(BOLD)EVERYTHING CLEANED$(COLOR_END)"
#
#bonus: $(NAME) $(OBJSB) .bonus
#	
#.bonus: $(OBJSB)
#	@touch .bonus
#	$(AR) $(NAME) $(OBJSB)
#	@echo "$(BLUE)$(BOLD)BONUS ADDED$(COLOR_END)"
#
#re: fclean all 
#
#-include $(DEPS)
#
#.PHONY: all clean fclean re bonus libft
#
#
#

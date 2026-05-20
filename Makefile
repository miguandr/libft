# Standard
NAME = libft.a

# Compiler & Flags
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f

# Directories
OBJ_DIR		= obj/
LIBFT_DIR	= libft/src/
FT_PRINTF_DIR	= ft_printf/src/
GNL_DIR		= get_next_line/src/

# Include flags per module
LIBFT_INC	= -I libft/include
PRINTF_INC	= -I ft_printf/include -I libft/include
GNL_INC		= -I get_next_line/include

# Source files
LIBFT_SRCS	= $(wildcard $(LIBFT_DIR)*.c)
FT_PRINTF_SRCS	= $(wildcard $(FT_PRINTF_DIR)*.c)
GNL_SRCS	= $(wildcard $(GNL_DIR)*.c)

# Object files
LIBFT_OBJS	= $(LIBFT_SRCS:$(LIBFT_DIR)%.c=$(OBJ_DIR)%.o)
FT_PRINTF_OBJS	= $(FT_PRINTF_SRCS:$(FT_PRINTF_DIR)%.c=$(OBJ_DIR)%.o)
GNL_OBJS	= $(GNL_SRCS:$(GNL_DIR)%.c=$(OBJ_DIR)%.o)

OBJS = $(LIBFT_OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS)

# Build rules
all: $(NAME)

$(NAME): libft_module ft_printf_module gnl_module
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "✓ $(NAME) ready"

libft_module: $(LIBFT_OBJS)
	@echo "  compiling libft..."

ft_printf_module: $(FT_PRINTF_OBJS)
	@echo "  compiling ft_printf..."

gnl_module: $(GNL_OBJS)
	@echo "  compiling get_next_line..."

$(OBJ_DIR)%.o: $(LIBFT_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

$(OBJ_DIR)%.o: $(FT_PRINTF_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(PRINTF_INC) -c $< -o $@

$(OBJ_DIR)%.o: $(GNL_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(GNL_INC) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "✓ object files removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "✓ $(NAME) removed"

re: fclean all

.PHONY: all clean fclean re libft_module ft_printf_module gnl_module

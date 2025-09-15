NAME       := libft.a
SRC_DIR    := src
OBJ_DIR    := obj
INCLUDE    := libft.h
CC         := cc
CFLAGS     := -Wall -Wextra -Werror -I .
GREEN      := \033[0;92m
YELLOW     := \033[0;93m
DEF_COLOR  := \033[0m

SRC_FILES  := $(shell find $(SRC_DIR) -type f -name "*.c")

OBJ        := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

OBJ_DIRS   := $(sort $(dir $(OBJ)))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling libft...$(DEF_COLOR)"
	@ar rcs $@ $^
	@echo "$(GREEN)Libft successfully compiled!$(DEF_COLOR)"

$(OBJ): | create_obj_dirs

create_obj_dirs:
	@mkdir -p $(OBJ_DIRS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiling: $<$(DEF_COLOR)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Removed object files$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)Library removed$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re create_obj_dirs

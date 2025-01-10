
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf

SRCS = src/csp.c \
       src/diu.c \
       src/xXP.c \
       src/printf.c

OBJ = $(SRCS:src/%.c=obj/%.o)

all: $(NAME)

obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	@echo "\033[32m✓ built successfully\033[0m"

clean:
	@$(RM) $(OBJ)
	@echo "\033[31m✓ objects removed\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[31m✓ removed\033[0m --> $(NAME)"
	@$(RM) -r obj/

re: fclean all

.PHONY: all clean fclean re


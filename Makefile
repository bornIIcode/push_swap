NAME = push_swap

CHECKER = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC = rules_stack_a.c rules_stack_b.c rules_stack_ab.c rm_cr_stack_a.c rm_cr_stack_b.c\
	  parsing.c free_func.c push_swap.c checking_func.c algo.c main.c ft_split.c utils.c\
	  get_next_line.c get_next_line_utils.c
	
SRCBONUS = rules_stack_a.c rules_stack_b.c rules_stack_ab.c rm_cr_stack_a.c rm_cr_stack_b.c\
	  parsing.c free_func.c push_swap.c checking_func.c algo.c checker.c ft_split.c utils.c\
	  get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

OBJBONUS = $(SRCBONUS:.c=.o)


all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(CHECKER): $(OBJBONUS)
	$(CC) $(CFLAGS) -o $(CHECKER) $(OBJBONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJBONUS)

fclean:clean
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: clean fclean re
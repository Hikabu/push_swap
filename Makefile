NAME			=	push_swap
BON				=	pibon
SRCS 			=	$(wildcard *.c)
HEADERS 		=	$(wildcard *.h)
OBJ 			=	$(SRCS:.c=.o)
CFLAGS 			=	-Wall -Wextra -Werror -g 
IFLAGS			=	-Ilibft
LFLAGS			=	-Llibft -lft
RM				=	rm -rf
BSRC			=	$(wildcard bonus/*.c)
BHEADERS 		=	$(wildcard bonus/*.h)
BOBJ 			=	$(BSRC:.c=.o)

YELLOW  = \033[33m
PURPLE  = \033[32m
END     = \033[0m

%.o: %.c $(HEADERS)
	@cc -c $(CFLAGS) $(IFLAGS) $< -o $@

all: libft $(NAME)

$(NAME): $(OBJ) 
	@cc $(CFLAGS) $(IFLAGS) $(OBJ) $(LFLAGS)  -o $@
	@echo "$(YELLOW) Executable file $(NAME) was compiled $(END)"
libft:
	@make $(MAKECMDGOALS) -C libft

bonus: libft $(BON)
$(BON): $(BOBJ)
	@cc $(CFLAGS) $(IFLAGS) $(BOBJ) -L./libft -lft -o $@
	@echo "$(YELLOW) Executable file $(BON) was compiled $(END)"

clean: libft
	@$(RM) $(OBJ) $(BOBJ)
	@echo "$(PURPLE) Executable file $(NAME) was deleted$(END)"

fclean:	clean
	@$(RM) $(NAME) $(BON)
	@echo "$(PURPLE) Executable file $(NAME) was compiled$(END)"
re:	fclean all

.PHONY: all clean fclean re libft bonus

